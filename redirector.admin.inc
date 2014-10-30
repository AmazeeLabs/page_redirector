<?php

/**
 * @file
 *  Admin callback for the overview page.
 */

/**
 * Page callback for the redirector overview page.
 */
function redirector_admin_overview() {
  return array('#markup' => 'Replacement for the view.');
}

/**
 * Adds or edits a test.
 */
function redirector_add_edit_test_page($form, $form_state, $test = NULL) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => !empty($test) ? $test->title : '',
  );
  // Show the source configurators.
  $form['source_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Source configuration'),
  );
  $configurators = redirector_get_source_configurators();
  if (!empty($configurators)) {
    foreach ($configurators as $configurator) {
      // @todo: we should maybe check here that the class exists and fallback
      // nicely if not.
      $elements = $configurator['class']::getFormElements();
      if (!empty($elements)) {
        $form['source_configuration'] += $elements;
      }
    }
  }

  // Show the expected configurators.
  $form['expected_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Expected configuration'),
  );
  $configurators = redirector_get_expected_configurators();
  if (!empty($configurators)) {
    foreach ($configurators as $configurator) {
      // @todo: we should maybe check here that the class exists and fallback
      // nicely if not.
      $elements = $configurator['class']::getFormElements();
      if (!empty($elements)) {
        $form['expected_configuration'] += $elements;
      }
    }
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  if (!empty($test)) {
    $form['tid'] = array(
      '#type' => 'value',
      '#value' => $test->tid,
    );
  }
  $form['#tree'] = TRUE;
  return $form;
}

/**
 * Submit handler for adding/editing a test.
 */
function redirector_add_edit_test_page_submit(&$form, &$form_state) {
  // @todo: load the test if we have a test id.
  $redirect_test = new stdClass();
  $redirect_test->created = REQUEST_TIME;

  $redirect_test->title = $form_state['values']['title'];
  $redirect_test->source_configuration = $form_state['values']['source_configuration'];
  $redirect_test->expected_configuration = $form_state['values']['expected_configuration'];
  $primary_keys = array();
  $message = t('The test has been saved.');
  if (!empty($redirect_test->tid)) {
    $primary_keys = array('tid');
    $message = t('The test has been updated');
  }
  drupal_write_record('redirector_tests', $redirect_test, $primary_keys);
  drupal_set_message($message);
}
