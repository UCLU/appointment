<?php
/**
 * @file
 * Entity information for the Appointments Slot entity type.
 */

/**
 * Implements hook_entity_property_info().
 */
function appointments_slot_entity_property_info() {
  $info = array();
  $properties = &$info['appointments_slot']['properties'];
  $properties = array(
    'slot_id' => array(
      'label' => t('Slot ID'),
      'description' => t('Primary key: the unique identifier for a slot.'),
      'type' => 'integer',
      'schema field' => 'slot_id',
    ),
    'type' => array(
      'label' => t('Type'),
      'type' => 'token',
      'description' => t('The slot type.'),
      'required' => TRUE,
      'schema field' => 'type',
      'options list' => 'appointments_slot_type_options',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'uid' => array(
      'label' => t('Owner'),
      'description' => t('The user who created or who owns the slot.'),
      'type' => 'user',
      'schema field' => 'uid',
    ),
    'published' => array(
      'label' => t('Published status'),
      'description' => t('Whether or not the slot is published.'),
      'type' => 'boolean',
      'options list' => 'appointments_slot_published_options',
      'schema field' => 'published',
      'required' => TRUE,
    ),
    'start_time' => array(
      'label' => t('Start time'),
      'description' => t('The date and time when the slot starts.'),
      'type' => 'date',
      'schema field' => 'start_time',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'end_time' => array(
      'label' => t('End time'),
      'description' => t('The date and time when the slot ends.'),
      'type' => 'date',
      'schema field' => 'end_time',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'webform_nid' => array(
      'label' => t('Webform'),
      'description' => t('The ID of the webform to be used for booking this slot.'),
      'type' => 'node',
      'schema field' => 'webform_nid',
    ),
    'capacity' => array(
      'label' => t('Remaining capacity'),
      'description' => t('The remaining capacity for this slot.'),
      'type' => 'integer',
      'schema field' => 'capacity',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'created' => array(
      'label' => t('Created date'),
      'description' => t('The date when the slot was created.'),
      'type' => 'date',
      'schema field' => 'created',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'changed' => array(
      'label' => t('Last modified date'),
      'description' => t('The date when the slot was last updated.'),
      'type' => 'date',
      'schema field' => 'changed',
      'setter callback' => 'entity_property_verbatim_set',
    ),
  );
  return $info;
}
