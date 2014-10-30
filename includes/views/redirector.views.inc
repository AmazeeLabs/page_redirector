<?php

/**
 * @file
 *  Views integration of the redirector module.
 */

/**
 * Implements hook_views_data().
 */
function redirector_views_data() {
  $data = array();

  $data['redirector_tests']['table']['group']  = t('Redirector tests');

  $data['redirector_tests']['table']['base'] = array(
    'field' => 'tid',
    'title' => t('Redirector tests'),
    'help' => t('Redirector tests'),
  );

  $data['redirector_tests']['table']['entity type'] = 'redirector_test';

  // The test id
  $data['redirector_tests']['tid'] = array(
    'title' => t('Test ID'),
    'help' => t('The unique internal identifier of the test.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // The title.
  $data['redirector_tests']['title'] = array(
    'title' => t('Title'),
    'help' => t('Title'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // When the test was created.
  $data['redirector_tests']['created'] = array(
    'title' => t('Created'),
    'help' => t('Created'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  return $data;
}
