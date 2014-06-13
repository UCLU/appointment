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

  $form_state['slot'] = $slot;

  $form['start_time'] = array(
    '#title' => t('Start time'),
    '#type' => 'date_popup',
    '#default_value' => $slot->is_new ? NULL : date('Y-m-d H:i:s', $slot->start_time),
    '#required' => TRUE,
  );

  $duration = $slot->is_new ? 60 : ($slot->end_time - $slot->start_time) / 60;

  $form['duration'] = array(
    '#title' => t('Duration'),
    '#type' => 'select',
    '#options' => array(
      30 => t('Half an hour'),
      60 => t('1 hour'),
      90 => t('1½ hours'),
    ),
    '#default_value' => $duration,
    '#required' => TRUE,
  );

  $form['capacity'] = array(
    '#title' => t('Capacity'),
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#size' => 4,
    '#default_value' => $slot->capacity,
    '#element_validate' => array('element_validate_integer'),
    '#required' => TRUE,
  );

  $form['published'] = array(
    '#title' => t('Status'),
    '#type' => 'select',
    '#options' => appointment_slot_published_options(),
    '#default_value' => $slot->published,
    '#required' => TRUE,
  );

  $form['buttons'] = array(
    '#type' => 'actions',
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => $slot->is_new ? t('Save (create new)') : t('Save (update)'),
  );
  return $form;
}

/**
 * Submit callback for adding or editing an appointment slot.
 */
function appointment_slot_form_submit($form, &$form_state) {
  $slot = $form_state['slot'];
  $is_new = empty($slot->slot_id);

  $slot->start_time = $form_state['values']['start_time'];
  $duration = $form_state['values']['duration'];
  $slot->end_time = date('Y-m-d H:i:s', strtotime($slot->start_time) + ($duration * 60));
  $slot->capacity = $form_state['values']['capacity'];
  $slot->published = $form_state['values']['published'];

  if ($is_new || !isset($slot->uid)) {
    $slot->uid = $GLOBALS['user']->uid;
  }

  $controller = entity_get_controller('appointment_slot');
  $controller->save($slot);
  $params = array(
      '%label' => entity_label('appointment_slot', $slot),
  );
  if ($is_new) {
    drupal_set_message(t('The slot %label has been created', $params));
  }
  else {
    drupal_set_message(t('The slot %label has been updated', $params));
  }
  if (empty($_GET['destination'])) {
    $form_state['redirect'] = 'admin/appointments/slots' . ($slot->slot_id ? '/' . $slot->slot_id : '');
  }
}
