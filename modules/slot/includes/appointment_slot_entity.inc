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

  /**
   * Get the end time of this slot.
   *
   * @return int
   *   A UNIX timestamp representing the start date and time.
   */
  public function getEndTime() {
    return strtotime($this->field_appointment_time[LANGUAGE_NONE][0]['value2']);
  }

}
