<?php
/**
 * @file
 * Default View showing an administrative list of appointment slots.
 */

$view = new view();
$view->name = 'appointment_slots';
$view->description = 'An administrative list of appointment slots.';
$view->tag = 'appointment';
$view->base_table = 'appointment_slot';
$view->human_name = 'Appointment Slots';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Appointment Slots';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'appointment slot: update any';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'slot_id' => 'slot_id',
  'field_appointment_host' => 'field_appointment_host',
  'field_appointment_time' => 'field_appointment_time',
  'field_appointment_capacity' => 'field_appointment_capacity',
  'published' => 'published',
  'created' => 'created',
  'changed' => 'changed',
  'nothing_1' => 'nothing_1',
  'nothing' => 'nothing_1',
  'nothing_2' => 'nothing_1',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'slot_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_appointment_host' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 1,
  ),
  'field_appointment_time' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_appointment_capacity' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'published' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'nothing_1' => array(
    'align' => 'views-align-center',
    'separator' => ' · ',
    'empty_column' => 0,
  ),
  'nothing' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'nothing_2' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'There are no slots to display.';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no slots to display.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Field: Appointment Slot: Slot ID */
$handler->display->display_options['fields']['slot_id']['id'] = 'slot_id';
$handler->display->display_options['fields']['slot_id']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['slot_id']['field'] = 'slot_id';
$handler->display->display_options['fields']['slot_id']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['slot_id']['alter']['path'] = 'appointments/slots/[slot_id]';
/* Field: Appointment Slot: Host */
$handler->display->display_options['fields']['field_appointment_host']['id'] = 'field_appointment_host';
$handler->display->display_options['fields']['field_appointment_host']['table'] = 'field_data_field_appointment_host';
$handler->display->display_options['fields']['field_appointment_host']['field'] = 'field_appointment_host';
$handler->display->display_options['fields']['field_appointment_host']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_appointment_host']['settings'] = array(
  'link' => 1,
);
/* Field: Appointment Slot: Date and time */
$handler->display->display_options['fields']['field_appointment_time']['id'] = 'field_appointment_time';
$handler->display->display_options['fields']['field_appointment_time']['table'] = 'field_data_field_appointment_time';
$handler->display->display_options['fields']['field_appointment_time']['field'] = 'field_appointment_time';
$handler->display->display_options['fields']['field_appointment_time']['label'] = 'Time';
$handler->display->display_options['fields']['field_appointment_time']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
);
/* Field: Appointment Slot: Capacity */
$handler->display->display_options['fields']['field_appointment_capacity']['id'] = 'field_appointment_capacity';
$handler->display->display_options['fields']['field_appointment_capacity']['table'] = 'field_data_field_appointment_capacity';
$handler->display->display_options['fields']['field_appointment_capacity']['field'] = 'field_appointment_capacity';
$handler->display->display_options['fields']['field_appointment_capacity']['settings'] = array(
  'thousand_separator' => ' ',
  'prefix_suffix' => 1,
);
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
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = 'Operations';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'View';
$handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'appointments/slots/[slot_id]';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Edit';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['path'] = 'appointments/slots/[slot_id]/edit';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_2']['label'] = 'Delete';
$handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Delete';
$handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'appointments/slots/[slot_id]/delete';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/structure/appointments/slots';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Appointment Slots';
$handler->display->display_options['menu']['name'] = 'management';

$views[$view->name] = $view;
