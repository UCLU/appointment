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
  'start_time' => 'start_time',
  'capacity' => 'capacity',
  'published' => 'published',
  'created' => 'created',
  'changed' => 'changed',
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
  'start_time' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'capacity' => array(
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
$handler->display->display_options['fields']['slot_id']['alter']['path'] = 'admin/appointments/slots/[slot_id]';
/* Field: Appointment Slot: Start time */
$handler->display->display_options['fields']['start_time']['id'] = 'start_time';
$handler->display->display_options['fields']['start_time']['table'] = 'appointment_slot';
$handler->display->display_options['fields']['start_time']['field'] = 'start_time';
$handler->display->display_options['fields']['start_time']['date_format'] = 'short';
/* Field: Appointment Slot: Remaining capacity */
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

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/appointments/slots';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Appointment Slots';
$handler->display->display_options['menu']['name'] = 'management';

$views[$view->name] = $view;
