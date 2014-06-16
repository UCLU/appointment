<?php
/**
 * @file
 * Entity controller for the 'appointment_booking' entity.
 */

class AppointmentBookingController extends EntityApiController {

  /**
   * Overrides EntityAPIController::load(), adding a 'slot' property.
   */
  public function load($ids = array(), $conditions = array()) {
    $entities = parent::load($ids, $conditions);
    $slot_ids = array();
    foreach ($entities as $entity) {
      $slot_ids[] = $entity->slot_id;
    }
    $slots = $slot_ids ? appointment_slot_load_multiple($slot_ids) : array();
    foreach ($entities as $entity) {
      $entity->slot = isset($slots[$entity->slot_id]) ? $slots[$entity->slot_id] : FALSE;
    }
    return $entities;
  }

  /**
   * Overrides EntityAPIController::create(), allowing defaults to be defined.
   */
  public function create(array $values = array()) {
    $default_values = array(
      'booking_id' => NULL,
      'slot_id' => NULL,
      'type' => 'default',
      'uid' => NULL,
      'booking_status' => 'draft',
      'anonymous_id' => NULL,
      'created' => NULL,
      'changed' => NULL,
    );
    // Overwrite default values with supplied values.
    $values = array_merge($default_values, $values);
    return parent::create($values);
  }

  /**
   * Overrides EntityAPIController::save().
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Determine whether the entity is new.
    $entity->is_new = empty($entity->booking_id);

    // Set 'created' and 'changed' fields.
    if ($entity->is_new || empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;

    if (!$entity->uid && $entity->is_new && $GLOBALS['user']->uid == 0) {
      $entity->anonymous_id = appointment_booking_get_anonymous_id();
    }

    return parent::save($entity, $transaction);
  }

}
