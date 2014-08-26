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
   * Get the start time of this slot.
   *
   * @return int|FALSE
   *   A UNIX timestamp representing the start date and time, or FALSE on
   *   failure.
   */
  public function getStartTime() {
    if (empty($this->field_appointment_time) || empty($this->field_appointment_time[LANGUAGE_NONE][0]['value2'])) {
      return FALSE;
    }
    return strtotime($this->field_appointment_time[LANGUAGE_NONE][0]['value']);
  }

  /**
   * Get the end time of this slot.
   *
   * @return int|FALSE
   *   A UNIX timestamp representing the end date and time, or FALSE on
   *   failure.
   */
  public function getEndTime() {
    if (empty($this->field_appointment_time) || empty($this->field_appointment_time[LANGUAGE_NONE][0]['value2'])) {
      return FALSE;
    }
    return strtotime($this->field_appointment_time[LANGUAGE_NONE][0]['value2']);
  }

  /**
   * Get the capacity for this slot.
   *
   * @return int|FALSE
   *   The remaining capacity for the slot, or FALSE on failure.
   */
  public function getCapacity() {
    if (empty($this->field_appointment_capacity) || empty($this->field_appointment_capacity[LANGUAGE_NONE][0]['value'])) {
      return FALSE;
    }
    return $this->field_appointment_capacity[LANGUAGE_NONE][0]['value'];
  }

}
