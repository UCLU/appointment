<?php
/**
 * @file
 * Appointment Booking entity class.
 */

class AppointmentBookingEntity extends Entity {

  /**
   * @{inheritdoc}
   */
  protected function defaultLabel() {
    return t("@user's booking: @slot", array(
      '@slot' => entity_label('appointment_slot', $this->slot),
      '@user' => format_username(user_load($this->uid)),
    ));
  }

  /**
   * @{inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'appointments/bookings/' . $this->booking_id);
  }

}
