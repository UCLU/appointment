<?php
/**
 * @file
 * Forms for the Appointment Booking module.
 */

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
function appointment_booking_form($form, &$form_state, AppointmentBookingEntity $booking) {
  $form_state['booking'] = $booking;

  $booking->is_new = empty($booking->booking_id);

  form_load_include($form_state, 'inc', 'appointment_booking', 'includes/appointment_booking.forms');

  global $user;

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#max_length' => 255,
    '#size' => 60,
    '#required' => TRUE,
  );

  if ($booking->name) {
    $form['name']['#default_value'] = $booking->name;
  }
  elseif ($user->uid) {
    $form['name']['#default_value'] = format_username($user);
  }

  $form['mail'] = array(
    '#title' => t('E-mail address'),
    '#type' => module_exists('elements') ? 'email' : 'textfield',
    '#max_length' => 255,
    '#size' => 60,
    '#required' => TRUE,
    '#element_validate' => array('appointment_booking_validate_mail'),
  );

  if ($booking->mail) {
    $form['mail']['#default_value'] = $booking->mail;
  }
  elseif ($user->uid) {
    $form['mail']['#default_value'] = $user->mail;
  }

  $form['booking_status'] = array(
    '#type' => 'value',
    '#value' => 'booked',
  );
  if (!$booking->is_new && user_access('appointment booking: update any')) {
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
 * Validate an e-mail address.
 */
function appointment_booking_validate_mail($element, &$form_state) {
  $value = $element['#value'];
  if ($value !== '' && !valid_email_address($value)) {
    form_error($element, t('%name must be a valid email address.', array('%name' => $element['#title'])));
  }
}

/**
 * Submit callback for editing an appointment booking.
 */
function appointment_booking_form_submit($form, &$form_state) {
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
    t('Are you sure you want to cancel this booking?'),
    $uri['path'],
    NULL,
    t('Yes'),
    t('No')
  );
}

/**
 * Submit callback for canceling an appointment booking.
 */
function appointment_booking_cancel_confirm_submit($form, &$form_state) {
  $booking = $form_state['booking'];
  $label = entity_label('appointment_booking', $booking);
  entity_get_controller('appointment_booking')->delete(array($booking->booking_id));
  drupal_set_message(t('The booking %label has been canceled.', array(
    '%label' => $label,
  )));
  if (empty($_GET['destination'])) {
    $form_state['redirect'] = 'appointments';
  }
}
