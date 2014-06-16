<?php
/**
 * @file
 * Appointment Booking entity class.
 */

class AppointmentBookingEntity extends Entity {

  public $slot;

  /**
   * @{inheritdoc}
   */
  protected function defaultLabel() {
    return t("@user's booking: @slot", array(
      '@slot' => entity_label('appointment_slot', $this->getSlot()),
      '@user' => format_username(user_load($this->uid)),
    ));
  }

  /**
   * @{inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'appointments/bookings/' . $this->booking_id);
  }

  /**
   * Get the slot for this booking.
   *
   * @return AppointmentSlotEntity|FALSE
   */
  public function getSlot() {
    if (empty($this->slot)) {
      if (empty($this->slot_id)) {
        throw new Exception('Slot not defined');
      }
      $this->slot = appointment_slot_load($this->slot_id);
    }
    return $this->slot;
  }

}
