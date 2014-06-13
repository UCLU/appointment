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
    return $this->booking_id;
  }

  /**
   * @{inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'appointments/bookings/' . $this->booking_id);
  }

}
