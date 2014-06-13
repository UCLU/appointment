<?php
/**
 * @file
 * Forms for the Appointment Slot module.
 */

/**
 * Form for adding or editing an appointment slot.
 *
 * @param array $form
 *   The Drupal form render array.
 * @param array &$form_state
 *   The Drupal form state array.
 * @param mixed $data
 *   A string (the slot type) or an object (the slot).
 */
function appointment_slot_form($form, &$form_state, $data) {

  $slot = is_object($data) ? $data : entity_create('appointment_slot', array('type' => $data));

  $slot->is_new = empty($slot->slot_id);

  $slot_path = FALSE;
  if ($slot->slot_id) {
    $uri = entity_uri('appointment_slot', $slot);
    $slot_path = $uri['path'];
  }

  $form_state['slot'] = $slot;

  $form['published'] = array(
    '#title' => t('Status'),
    '#type' => 'select',
    '#options' => appointment_slot_published_options(),
    '#default_value' => $slot->published,
    '#required' => TRUE,
  );

  form_load_include($form_state, 'inc', 'appointment_slot', 'includes/appointment_slot.forms');

  field_attach_form('appointment_slot', $slot, $form, $form_state);

  $form['buttons'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => $slot->is_new ? t('Save new slot') : t('Save slot'),
  );

  $cancel_path = $slot_path ? $slot_path : 'admin/appointments/slots';
  if (!empty($_GET['destination'])) {
    $options = drupal_parse_url($_GET['destination']);
    $cancel_path = $options['path'];
  }
  $form['buttons']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => $cancel_path,
  );

  return $form;
}

/**
 * Validation callback for adding or editing an appointment slot.
 */
function appointment_slot_form_validate(&$form, &$form_state) {
  $slot = $form_state['slot'];
  field_attach_form_validate('appointment_slot', $slot, $form, $form_state);
}

/**
 * Submit callback for adding or editing an appointment slot.
 */
function appointment_slot_form_submit($form, &$form_state) {
  $slot = $form_state['slot'];
  $is_new = empty($slot->slot_id);

  $slot->published = $form_state['values']['published'];

  if ($is_new || !isset($slot->uid)) {
    $slot->uid = $GLOBALS['user']->uid;
  }

  field_attach_submit('appointment_slot', $slot, $form, $form_state);

  // Save the slot.
  entity_get_controller('appointment_slot')->save($slot);

  $params = array(
    '%label' => entity_label('appointment_slot', $slot),
  );
  if ($is_new) {
    drupal_set_message(t('Created new slot: %label', $params));
  }
  else {
    drupal_set_message(t('Updated slot: %label', $params));
  }
  if (empty($_GET['destination'])) {
    $path = 'admin/appointments/slots';
    if ($slot->slot_id) {
      $uri = entity_uri('appointment_slot', $slot);
      $path = $uri['path'];
    }
    $form_state['redirect'] = $path;
  }
}

/**
 * Form to confirm the delete action for an appointment slot.
 */
function appointment_slot_delete_confirm($form, &$form_state, AppointmentSlotEntity $slot) {
  $form_state['slot'] = $slot;
  $form['slot_id'] = array(
    '#type' => 'value',
    '#value' => $slot->slot_id,
  );
  $uri = entity_uri('appointment_slot', $slot);
  return confirm_form(
    $form,
    t('Are you sure you want to delete the slot #@id?', array('@id' => $slot->slot_id)),
    $uri['path'],
    NULL,
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback for deleting an appointment slot.
 */
function appointment_slot_delete_confirm_submit($form, &$form_state) {
  $slot = $form_state['slot'];
  entity_get_controller('appointment_slot')->delete(array($slot->slot_id));
  drupal_set_message(t('The slot @id has been deleted.', array(
    '@id' => $slot->slot_id,
  )));
  if (empty($_GET['destination'])) {
    $form_state['redirect'] = 'admin/appointments/slots';
  }
}
