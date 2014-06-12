<?php
/**
 * @file
 * Forms for the Appointments Slot module.
 */

/**
 * Form for creating an appointment slot.
 */
function appointments_slot_add_form($form, &$form_state) {
  $form['start_time'] = array(
    '#title' => t('Start time'),
    '#type' => 'textfield',
  );
  return $form;
}
