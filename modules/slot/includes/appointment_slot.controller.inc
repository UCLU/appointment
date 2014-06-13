<?php
/**
 * @file
 * Entity controller for the 'appointment_slot' entity.
 */

class AppointmentSlotController extends EntityApiController {

  /**
   * Overrides EntityAPIController::create(), allowing defaults to be defined.
   */
  public function create(array $values = array()) {
    $default_values = array(
      'slot_id' => NULL,
      'type' => 'default',
      'uid' => NULL,
      'published' => 0,
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
    $entity->is_new = empty($entity->slot_id);

    // Set 'created' and 'changed' fields.
    if ($entity->is_new || empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;

    return parent::save($entity, $transaction);
  }

}
