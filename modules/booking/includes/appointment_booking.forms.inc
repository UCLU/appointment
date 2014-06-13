<?php
/**
 * @file
 * Forms for the Appointment Booking module.
 */

/**
 * Form for making an appointment booking.
 *
 * @param array $form
 *   The Drupal form render array.
 * @param array &$form_state
 *   The Drupal form state array.
 * @param object $slot
 *   The appointment slot entity object.
 * @param mixed $data
 *   A string (the booking type) or an object (the booking).
 */
function appointment_booking_form($form, &$form_state, $slot) {

  $booking = entity_create('appointment_booking', array(
    'slot_id' => $slot->slot_id,
  ));

  $booking->is_new = TRUE;

  $form_state['booking'] = $booking;

  form_load_include($form_state, 'inc', 'appointment_booking', 'includes/appointment_booking.forms');

  field_attach_form('appointment_booking', $booking, $form, $form_state);

  $form['buttons'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit booking'),
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
 * Validation callback for adding or editing an appointment booking.
 */
function appointment_booking_form_validate(&$form, &$form_state) {
  $booking = $form_state['booking'];
  field_attach_form_validate('appointment_booking', $booking, $form, $form_state);
}

/**
 * Submit callback for adding an appointment booking.
 */
function appointment_booking_form_submit($form, &$form_state) {
  $booking = $form_state['booking'];

  $booking->uid = $GLOBALS['user']->uid;

  field_attach_submit('appointment_booking', $booking, $form, $form_state);

  // Save the booking.
  entity_get_controller('appointment_booking')->save($booking);

  $params = array(
    '%label' => entity_label('appointment_booking', $booking),
  );
  drupal_set_message(t('Created new booking: %label', $params));
}

/**
 * Form for editing an appointment booking.
 *
 * @param array $form
 *   The Drupal form render array.
 * @param array &$form_state
 *   The Drupal form state array.
 * @param object $booking
 *   The appointment booking entity object.
 */
function appointment_booking_edit_form($form, &$form_state, $booking) {

  $form_state['booking'] = $booking;

  form_load_include($form_state, 'inc', 'appointment_booking', 'includes/appointment_booking.forms');

  $form['booking_status'] = array(
    '#title' => t('Booking status'),
    '#type' => 'select',
    '#options' => appointment_booking_status_options(),
    '#default_value' => $booking->booking_status,
  );

  field_attach_form('appointment_booking', $booking, $form, $form_state);

  $form['buttons'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit booking'),
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

  if (isset($form_state['values']['booking_status'])) {
    $booking->booking_status = $form_state['values']['booking_status'];
  }

  field_attach_submit('appointment_booking', $booking, $form, $form_state);

  // Save the booking.
  entity_get_controller('appointment_booking')->save($booking);

  $params = array(
    '%label' => entity_label('appointment_booking', $booking),
  );
  drupal_set_message(t('Updated booking: %label', $params));
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
