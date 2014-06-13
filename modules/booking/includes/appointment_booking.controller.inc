<?php
/**
 * @file
 * Entity controller for the 'appointment_booking' entity.
 */

class AppointmentBookingController extends EntityApiController {

  /**
   * Overrides EntityAPIController::create(), allowing defaults to be defined.
   */
  public function create(array $values = array()) {
    $default_values = array(
      'booking_id' => NULL,
      'slot_id' => NULL,
      'uid' => NULL,
      'booking_status' => 'draft',
      'webform_nid' => NULL,
      'webform_sid' => NULL,
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

    return parent::save($entity, $transaction);
  }

}
