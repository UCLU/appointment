<?php
/**
 * @file
 * Appointment Slot entity class.
 */

class AppointmentSlotEntity extends Entity {

  /**
   * @{inheritdoc}
   */
  protected function defaultLabel() {
    return t('Slot #@id', array('@id' => $this->slot_id));
  }

  /**
   * @{inheritdoc}
   */
  protected function defaultUri() {
    return array(
      'path' => 'appointments/slots/' . $this->slot_id,
    );
  }

}
