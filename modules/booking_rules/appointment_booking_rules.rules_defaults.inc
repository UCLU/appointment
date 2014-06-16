<?php
/**
 * @file
 * appointment_booking_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function appointment_booking_rules_default_rules_configuration() {
  $items = array();
  $items['rules_appointment_booking_reduce_capacity'] = entity_import('rules_config', '{ "rules_appointment_booking_reduce_capacity" : {
      "LABEL" : "Reduce capacity after booking",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "appointment_booking" ],
      "ON" : { "appointment_booking_insert" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "appointment-booking:slot-id" ],
            "field" : "field_appointment_capacity"
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "appointment-booking:slot-id:field-appointment-capacity" ],
            "value" : {
              "select" : "appointment-booking:slot-id:field-appointment-capacity",
              "num_offset" : { "value" : "-1" }
            }
          }
        },
        { "entity_save" : { "data" : [ "appointment-booking:slot-id" ] } }
      ]
    }
  }');
  $items['rules_appointment_booking_restore_capacity'] = entity_import('rules_config', '{ "rules_appointment_booking_restore_capacity" : {
      "LABEL" : "Restore capacity after canceling a booking",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "appointment_booking" ],
      "ON" : { "appointment_booking_delete" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "appointment-booking:slot-id" ],
            "field" : "field_appointment_capacity"
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "appointment-booking:slot-id:field-appointment-capacity" ],
            "value" : {
              "select" : "appointment-booking:slot-id:field-appointment-capacity",
              "num_offset" : { "value" : "1" }
            }
          }
        },
        { "entity_save" : { "data" : [ "appointment-booking:slot-id" ] } }
      ]
    }
  }');
  return $items;
}
