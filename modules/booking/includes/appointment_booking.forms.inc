<?php
/**
 * @file
 * Forms for the Appointment Booking module.
 */

/**
 * Page for booking an appointment.
 *
 * @param AppointmentSlotEntity $slot
 */
function appointment_booking_page(AppointmentSlotEntity $slot) {
  $booking = appointment_booking_load_by_user($slot);
  if (!$booking) {
    $booking = entity_create('appointment_booking', array(
      'slot_id' => $slot->slot_id,
      'uid' => $GLOBALS['user']->uid,
      'booking_status' => 'draft',
    ));
  }
  return array(
    'booking_form' => drupal_get_form('appointment_booking_edit_form', $booking),
  );
}

/**
 * Form for making an appointment booking.
 *
 * @param array $form
 *   The Drupal form render array.
 * @param array &$form_state
 *   The Drupal form state array.
 * @param AppointmentSlotEntity $slot
 *   The appointment slot entity object.
 */
function appointment_booking_make_form($form, &$form_state, AppointmentSlotEntity $slot) {
  $booking = appointment_booking_load_by_user($slot);
  if ($booking) {
    $status_options = appointment_booking_status_options();
    $form['book']['#markup'] = t('!status booking', array(
      '!status' => $status_options[$booking->booking_status],
    ));
    if ($booking->booking_status == 'booked') {
      $form['book']['#markup'] = t('Booked');
    }
    $destination = drupal_get_destination();
    if (appointment_booking_access('update', $booking)) {
      $params = array(
        '@edit' => url('appointments/bookings/' . $booking->booking_id . '/edit', array('query' => $destination)),
      );
      $form['book']['#markup'] .= ' ' . t('(<a href="@edit">edit</a>)', $params);
    }
    if ($booking->booking_status != 'canceled' && appointment_booking_access('cancel', $booking)) {
      $params = array(
        '@cancel' => url('appointments/bookings/' . $booking->booking_id . '/cancel', array('query' => $destination)),
      );
      $form['book']['#markup'] .= ' ' . t('(<a href="@cancel">cancel</a>)', $params);
    }
    return $form;
  }
  form_load_include($form_state, 'inc', 'appointment_booking', 'includes/appointment_booking.forms');
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Book'),
  );
  $form_state['slot'] = $slot;
  return $form;
}

/**
 * Submit callback for making a booking.
 */
function appointment_booking_make_form_submit($form, &$form_state) {
  $slot = $form_state['slot'];
  $booking = entity_create('appointment_booking', array(
    'slot_id' => $slot->slot_id,
    'uid' => $GLOBALS['user']->uid,
    'booking_status' => 'draft',
  ));
  entity_get_controller('appointment_booking')->save($booking);
  $uri = entity_uri('appointment_booking', $booking);
  if ($uri) {
    $form_state['redirect'] = $uri['path'];
  }
}

/**
 * Form for editing an appointment booking.
 *
 * @param array $form
 *   The Drupal form render array.
 * @param array &$form_state
 *   The Drupal form state array.
 * @param AppointmentBookingEntity $booking
 *   The appointment booking entity object.
 */
function appointment_booking_edit_form($form, &$form_state, AppointmentBookingEntity $booking) {
  $form_state['booking'] = $booking;

  $booking->is_new = empty($booking->booking_id);

  form_load_include($form_state, 'inc', 'appointment_booking', 'includes/appointment_booking.forms');

  if (appointment_booking_access('update', $booking)) {
    $form['booking_status'] = array(
      '#title' => t('Booking status'),
      '#type' => 'select',
      '#options' => appointment_booking_status_options(),
      '#default_value' => $booking->booking_status,
    );
  }

  field_attach_form('appointment_booking', $booking, $form, $form_state);

  $form['buttons'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => $booking->is_new ? t('Book') : t('Save'),
  );

  if (!empty($_GET['destination'])) {
    $options = drupal_parse_url($_GET['destination']);
    $cancel_path = $options['path'];
    $form['buttons']['cancel'] = array(
      '#type' => 'link',
      '#title' => t('Cancel'),
      '#href' => $cancel_path,
    );
  }

  return $form;
}

/**
 * Submit callback for editing an appointment booking.
 */
function appointment_booking_edit_form_submit($form, &$form_state) {
  $booking = $form_state['booking'];

  $is_new = empty($booking->booking_id);

  if (isset($form_state['values']['booking_status'])) {
    $booking->booking_status = $form_state['values']['booking_status'];
  }

  field_attach_submit('appointment_booking', $booking, $form, $form_state);

  // Save the booking.
  entity_get_controller('appointment_booking')->save($booking);

  $params = array(
    '%label' => entity_label('appointment_booking', $booking),
  );
  if ($is_new) {
    drupal_set_message(t('Created booking: %label', $params));
  }
  else {
    drupal_set_message(t('Updated booking: %label', $params));
  }

  if (empty($_GET['destination'])) {
    $uri = entity_uri('appointment_booking', $booking);
    if ($uri) {
      $form_state['redirect'] = $uri['path'];
    }
  }
}

/**
 * Form to confirm the cancel action for an appointment booking.
 */
function appointment_booking_cancel_confirm($form, &$form_state, AppointmentBookingEntity $booking) {
  $form_state['booking'] = $booking;
  $form['booking_id'] = array(
    '#type' => 'value',
    '#value' => $booking->booking_id,
  );
  $uri = entity_uri('appointment_booking', $booking);
  return confirm_form(
    $form,
    t('Are you sure you want to cancel the booking #@id?', array('@id' => $booking->booking_id)),
    $uri['path'],
    '',
    t('Yes'),
    t('No')
  );
}

/**
 * Submit callback for canceling an appointment booking.
 */
function appointment_booking_cancel_confirm_submit($form, &$form_state) {
  $booking = $form_state['booking'];
  $booking->booking_status = 'canceled';
  entity_get_controller('appointment_booking')->save($booking);
  drupal_set_message(t('The booking @id has been canceled.', array(
    '@id' => $booking->booking_id,
  )));
  if (empty($_GET['destination'])) {
    $form_state['redirect'] = 'admin/appointments/bookings';
  }
}

/**
 * Form to confirm the delete action for an appointment booking.
 */
function appointment_booking_delete_confirm($form, &$form_state, AppointmentBookingEntity $booking) {
  $form_state['booking'] = $booking;
  $form['booking_id'] = array(
    '#type' => 'value',
    '#value' => $booking->booking_id,
  );
  $uri = entity_uri('appointment_booking', $booking);
  return confirm_form(
    $form,
    t('Are you sure you want to delete the booking #@id?', array('@id' => $booking->booking_id)),
    $uri['path'],
    NULL,
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback for deleting an appointment booking.
 */
function appointment_booking_delete_confirm_submit($form, &$form_state) {
  $booking = $form_state['booking'];
  entity_get_controller('appointment_booking')->delete(array($booking->booking_id));
  drupal_set_message(t('The booking @id has been deleted.', array(
    '@id' => $booking->booking_id,
  )));
  if (empty($_GET['destination'])) {
    $form_state['redirect'] = 'admin/appointments/bookings';
  }
}
