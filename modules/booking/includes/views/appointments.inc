<?php
/**
 * @file
 * Default View showing a list of appointment slots for booking.
 */

$view = new view();
$view->name = 'appointments';
$view->description = 'A list of appointment slots.';
$view->tag = 'appointment';
$view->base_table = 'appointment_slot';
$view->human_name = 'Appointments';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Appointments';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'appointment slot: view published';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'teaser';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'There are no appointment slots to display.';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<p>There are no appointment slots to display.</p>';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
/* Field: Appointment Slot: Slot ID */
$handler->display->display_options['fields']['slot_id']['id'] = 'slot_id';
$handler->display->display_options['fields']['slot_id']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['slot_id']['field'] = 'slot_id';
$handler->display->display_options['fields']['slot_id']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['slot_id']['alter']['path'] = 'admin/appointments/slots/[slot_id]';
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['start_time']['id'] = 'start_time';
$handler->display->display_options['fields']['start_time']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['start_time']['field'] = 'start_time';
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['end_time']['id'] = 'end_time';
$handler->display->display_options['fields']['end_time']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['end_time']['field'] = 'end_time';
$handler->display->display_options['fields']['end_time']['label'] = 'End time';
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['capacity']['id'] = 'capacity';
$handler->display->display_options['fields']['capacity']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['capacity']['field'] = 'capacity';
/* Field: Appointment Slot: Published status */
$handler->display->display_options['fields']['published']['id'] = 'published';
$handler->display->display_options['fields']['published']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['published']['field'] = 'published';
$handler->display->display_options['fields']['published']['label'] = 'Published';
/* Field: Appointment Slot: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: Appointment Slot: Last modified date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Last modified';
$handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
/* Sort criterion: Appointment Slot: Date and time -  start date (field_appointment_time) */
$handler->display->display_options['sorts']['field_appointment_time_value']['id'] = 'field_appointment_time_value';
$handler->display->display_options['sorts']['field_appointment_time_value']['table'] = 'field_data_field_appointment_time';
$handler->display->display_options['sorts']['field_appointment_time_value']['field'] = 'field_appointment_time_value';
/* Filter criterion: Appointment Slot: Published status */
$handler->display->display_options['filters']['published']['id'] = 'published';
$handler->display->display_options['filters']['published']['table'] = 'appointment_slot';
$handler->display->display_options['filters']['published']['field'] = 'published';
$handler->display->display_options['filters']['published']['value'] = array(
  1 => '1',
);
/* Filter criterion: Appointment Slot: Date and time -  start date (field_appointment_time) */
$handler->display->display_options['filters']['field_appointment_time_value']['id'] = 'field_appointment_time_value';
$handler->display->display_options['filters']['field_appointment_time_value']['table'] = 'field_data_field_appointment_time';
$handler->display->display_options['filters']['field_appointment_time_value']['field'] = 'field_appointment_time_value';
$handler->display->display_options['filters']['field_appointment_time_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_appointment_time_value']['default_date'] = 'now';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'appointments';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Appointments';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

$views[$view->name] = $view;
