<?php
/**
 * @file
 * Views integration for the Appointments Slot module.
 */

/**
 * Implements hook_views_default_views().
 */
function appointments_slot_views_default_views() {
  $views_dir = drupal_get_path('module', 'appointments_slot') . '/includes/views';
  $views_files = scandir($views_dir);
  $views = array();
  foreach ($views_files as $filename) {
    if (substr($filename, -4) == '.inc') {
      include_once $views_dir . '/' . $filename;
    }
  }
  return $views;
}
