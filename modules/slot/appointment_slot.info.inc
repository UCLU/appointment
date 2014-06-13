<?php
/**
 * @file
 * Entity information for the Appointment Slot entity type.
 */

/**
 * Implements hook_entity_property_info().
 */
function appointment_slot_entity_property_info() {
  $info = array();
  $properties = &$info['appointment_slot']['properties'];
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
      'options list' => 'appointment_slot_type_options',
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
      'options list' => 'appointment_slot_published_options',
      'schema field' => 'published',
      'required' => TRUE,
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
