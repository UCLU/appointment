<?php
/**
 * @file
 * Theme and preprocess functions for the Appointment Slot module.
 */

/**
 * Process variables for appointment-slot.tpl.php.
 *
 * The $variables['elements'] array contains the following arguments:
 * - #slot
 * - #view_mode
 *
 * @see appointment-slot.tpl.php
 */
function template_preprocess_appointment_slot(&$variables) {

  $slot = $variables['elements']['#slot'];
  $view_mode = $variables['elements']['#view_mode'];

  // Detect whether the slot is on its own page.
  $is_page = $view_mode == 'full';
  if (!$is_page) {
    $page_slot = menu_get_object('appointment_slot');
    $is_page = $page_slot && $page_slot->slot_id == $slot->slot_id;
  }

  // Create some basic useful variables.
  $variables['view_mode'] = $view_mode;
  $variables['teaser'] = ($view_mode == 'teaser');
  $variables['page'] = $is_page;
  $variables['slot'] = $slot;
  $variables['label'] = entity_label('appointment_slot', $slot);

  // Flatten the $election object's member fields.
  $variables = array_merge((array) $slot, $variables);

  // Create the $content variable to contain fields for templates.
  $variables += array('content' => array());
  foreach (element_children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

  // Make the field variables available with the appropriate language.
  field_attach_preprocess('appointment_slot', $slot, $variables['content'], $variables);

  $variables['classes_array'][] = drupal_html_class('appointment-slot-type-' . $slot->type);
  if ($view_mode == 'teaser') {
    $variables['classes_array'][] = 'appointment-slot-teaser';
  }
  if (!$slot->published) {
    $variables['classes_array'][] = 'appointment-slot-unpublished';
  }
}
