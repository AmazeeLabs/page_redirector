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
  // Show the target configurators.
  $form['target_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Target configuration'),
  );
  $configurators = redirector_get_target_configurators();
  if (!empty($configurators)) {
    foreach ($configurators as $configurator) {
      // @todo: we should maybe check here that the class exists and fallback
      // nicely if not.
      $elements = $configurator['class']::getFormElements($test);
      if (!empty($elements)) {
        $form['target_configuration'] += $elements;
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
      $elements = $configurator['class']::getFormElements($test);
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
  // Load the redirector test if we have one, or create a new one otherwise.
  $message = t('The test has been saved.');
  if (!empty($form_state['values']['tid'])) {
    $redirect_test = redirector_load($form_state['values']['tid']);
    $message = t('The test has been updated');
  }
  else {
    $redirect_test = entity_get_controller('redirector_test')->create();
  }

  // Add the new values into the object.
  $redirect_test->title = $form_state['values']['title'];
  $redirect_test->target_configuration = $form_state['values']['target_configuration'];
  $redirect_test->expected_configuration = $form_state['values']['expected_configuration'];

  // And save it.
  entity_get_controller('redirector_test')->save($redirect_test);
  drupal_set_message($message);
  $form_state['redirect'] = 'admin/config/system/redirector';
}

/**
 * Page callback for running a single test.
 *
 * @param object $test
 *  A redirector test object obtained from a call to redirector_laod().
 */
function redirector_run_test_page($test) {
  entity_get_controller('redirector_test')->runTest($test);
  drupal_set_message(t('The test has run.'));
  drupal_goto('admin/config/system/redirector');
}
