<?php
/**
 * @file
 * Entity information for the Appointment Booking entity type.
 */

/**
 * Implements hook_entity_property_info().
 */
function appointment_booking_entity_property_info() {
  $info = array();
  $properties = &$info['appointment_booking']['properties'];
  $properties = array(
    'booking_id' => array(
      'label' => t('Booking ID'),
      'description' => t('Primary key: the unique identifier for a booking'),
      'type' => 'integer',
      'schema field' => 'booking_id',
    ),
    'slot_id' => array(
      'label' => t('Slot'),
      'description' => t('The appointment slot for this booking'),
      'type' => 'appointment_slot',
      'schema field' => 'slot_id',
    ),
    'booking_status' => array(
      'label' => t('Status'),
      'type' => 'token',
      'description' => t('The booking status'),
      'required' => TRUE,
      'schema field' => 'booking_status',
      'options list' => 'appointment_booking_status_options',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'type' => array(
      'label' => t('Type'),
      'type' => 'token',
      'description' => t('The booking type'),
      'required' => TRUE,
      'schema field' => 'type',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'name' => array(
      'label' => t('Name'),
      'type' => 'string',
      'description' => t('The name of the appointment guest'),
      'required' => FALSE,
      'schema field' => 'name',
    ),
    'mail' => array(
      'label' => t('E-mail address'),
      'type' => 'string',
      'description' => t('The e-mail address of the appointment guest'),
      'required' => TRUE,
      'schema field' => 'mail',
    ),
    'anonymous_id' => array(
      'label' => t('Session hash'),
      'type' => 'token',
      'description' => t("A hash of the user's session ID"),
      'required' => FALSE,
      'schema field' => 'anonymous_id',
    ),
    'uid' => array(
      'label' => t('User'),
      'description' => t('The user who created or who owns the booking'),
      'type' => 'user',
      'schema field' => 'uid',
    ),
    'created' => array(
      'label' => t('Created date'),
      'description' => t('The date when the slot was created'),
      'type' => 'date',
      'schema field' => 'created',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'changed' => array(
      'label' => t('Last modified date'),
      'description' => t('The date when the slot was last updated'),
      'type' => 'date',
      'schema field' => 'changed',
      'setter callback' => 'entity_property_verbatim_set',
    ),
  );
  return $info;
}
