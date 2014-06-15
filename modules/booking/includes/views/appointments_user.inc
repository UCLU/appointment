<?php
/**
 * @file
 * Default View showing a list of appointments booked by the user.
 */

$view = new view();
$view->name = 'appointments_user';
$view->description = "A list of the user's own appointments";
$view->tag = 'appointment';
$view->base_table = 'appointment_booking';
$view->human_name = 'My appointments';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My appointments';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'appointment booking: create';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'changed' => 'changed',
  'booking_status' => 'booking_status',
  'field_appointment_time' => 'field_appointment_time',
);
$handler->display->display_options['style_options']['default'] = 'field_appointment_time';
$handler->display->display_options['style_options']['info'] = array(
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'booking_status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_appointment_time' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: Appointment Booking: Slot */
$handler->display->display_options['relationships']['slot_id']['id'] = 'slot_id';
$handler->display->display_options['relationships']['slot_id']['table'] = 'appointment_booking';
$handler->display->display_options['relationships']['slot_id']['field'] = 'slot_id';
$handler->display->display_options['relationships']['slot_id']['required'] = TRUE;
/* Field: Appointment Booking: Last modified date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Created / modified';
$handler->display->display_options['fields']['changed']['date_format'] = 'today time ago';
$handler->display->display_options['fields']['changed']['second_date_format'] = 'short';
/* Field: Appointment Booking: Status */
$handler->display->display_options['fields']['booking_status']['id'] = 'booking_status';
$handler->display->display_options['fields']['booking_status']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['booking_status']['field'] = 'booking_status';
/* Field: Appointment Slot: Date and time */
$handler->display->display_options['fields']['field_appointment_time']['id'] = 'field_appointment_time';
$handler->display->display_options['fields']['field_appointment_time']['table'] = 'field_data_field_appointment_time';
$handler->display->display_options['fields']['field_appointment_time']['field'] = 'field_appointment_time';
$handler->display->display_options['fields']['field_appointment_time']['relationship'] = 'slot_id';
$handler->display->display_options['fields']['field_appointment_time']['label'] = 'Appointment time';
$handler->display->display_options['fields']['field_appointment_time']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
);
/* Contextual filter: Appointment Booking: User */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'appointment_booking';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
$handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Appointment Slot: Date and time -  start date (field_appointment_time) */
$handler->display->display_options['filters']['field_appointment_time_value']['id'] = 'field_appointment_time_value';
$handler->display->display_options['filters']['field_appointment_time_value']['table'] = 'field_data_field_appointment_time';
$handler->display->display_options['filters']['field_appointment_time_value']['field'] = 'field_appointment_time_value';
$handler->display->display_options['filters']['field_appointment_time_value']['relationship'] = 'slot_id';
$handler->display->display_options['filters']['field_appointment_time_value']['operator'] = '<';
$handler->display->display_options['filters']['field_appointment_time_value']['default_date'] = 'now';

/* Display: Future appointments */
$handler = $view->new_display('page', 'Future appointments', 'page');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Appointment Slot: Date and time -  start date (field_appointment_time) */
$handler->display->display_options['filters']['field_appointment_time_value']['id'] = 'field_appointment_time_value';
$handler->display->display_options['filters']['field_appointment_time_value']['table'] = 'field_data_field_appointment_time';
$handler->display->display_options['filters']['field_appointment_time_value']['field'] = 'field_appointment_time_value';
$handler->display->display_options['filters']['field_appointment_time_value']['relationship'] = 'slot_id';
$handler->display->display_options['filters']['field_appointment_time_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_appointment_time_value']['default_date'] = 'now';
$handler->display->display_options['path'] = 'user/%/appointments/future';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Future';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['type'] = 'tab';
$handler->display->display_options['tab_options']['title'] = 'My appointments';
$handler->display->display_options['tab_options']['weight'] = '3';

/* Display: Past appointments */
$handler = $view->new_display('page', 'Past appointments', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'My appointments (past)';
$handler->display->display_options['path'] = 'user/%/appointments/past';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Past';
$handler->display->display_options['menu']['weight'] = '1';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

$views[$view->name] = $view;
