<?php
/**
 * @file
 * Default View showing an administrative list of appointment bookings.
 */

$view = new view();
$view->name = 'appointment_bookings';
$view->description = '';
$view->tag = 'appointment_booking';
$view->base_table = 'appointment_booking';
$view->human_name = 'Bookings';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Bookings';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'booking_id' => 'booking_id',
  'uid' => 'uid',
  'slot_id' => 'slot_id',
  'booking_status' => 'booking_status',
  'created' => 'created',
  'changed' => 'changed',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'booking_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'uid' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'slot_id' => array(
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
$handler->display->display_options['empty']['area']['label'] = 'There are no bookings to display';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no bookings to display.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Field: Appointment Booking: Booking ID */
$handler->display->display_options['fields']['booking_id']['id'] = 'booking_id';
$handler->display->display_options['fields']['booking_id']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['booking_id']['field'] = 'booking_id';
$handler->display->display_options['fields']['booking_id']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['booking_id']['alter']['path'] = 'appointments/bookings/[booking_id]';
/* Field: Appointment Booking: User */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
/* Field: Appointment Booking: Slot */
$handler->display->display_options['fields']['slot_id']['id'] = 'slot_id';
$handler->display->display_options['fields']['slot_id']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['slot_id']['field'] = 'slot_id';
/* Field: Appointment Booking: Status */
$handler->display->display_options['fields']['booking_status']['id'] = 'booking_status';
$handler->display->display_options['fields']['booking_status']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['booking_status']['field'] = 'booking_status';
/* Field: Appointment Booking: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Appointment Booking: Last modified date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'appointment_booking';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Last modified';
$handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
$handler->display->display_options['fields']['changed']['second_date_format'] = 'long';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/appointments/bookings';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Bookings';
$handler->display->display_options['menu']['name'] = 'management';

$views[$view->name] = $view;
