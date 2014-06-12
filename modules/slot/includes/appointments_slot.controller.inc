<?php
/**
 * @file
 * Entity controller for the 'appointments_slot' entity.
 */

class AppointmentsSlotController extends EntityApiController {

  /**
   * Overrides EntityAPIController::create(), allowing defaults to be defined.
   */
  public function create(array $values = array()) {
    $default_values = array(
      'slot_id' => NULL,
      'type' => 'default',
      'uid' => NULL,
      'published' => 0,
      'start_time' => NULL,
      'end_time' => NULL,
      'webform_nid' => NULL,
      'capacity' => 0,
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
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

    // Convert timestamp fields.
    foreach ($entity as $property => $value) {
      if (substr($property, -5) == '_time' && !empty($value) && !is_numeric($value)) {
        $entity->$property = strtotime($value);
      }
    }

    // Set 'created' and 'changed' fields.
    if (empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;

    return parent::save($entity, $transaction);
  }

}
