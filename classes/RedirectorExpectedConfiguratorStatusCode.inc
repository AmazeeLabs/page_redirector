<?php

/**
 * @file
 *  Class for configuring the expected status code.
 */

class RedirectorExpectedConfiguratorStatusCode implements RedirectorExpectedConfiguratorInterface {

  /**
   * @see RedirectorExpectedConfiguratorInterface::getFormElements()
   */
  public static function getFormElements($redirector_test = NULL) {
    return array('status_code' => array(
      '#type' => 'textfield',
      '#title' => t('Status code'),
      '#description' => t('The status code of the response. If empty, it will default to 200.'),
      '#default_value' => !empty($redirector_test->expected_configuration) ? $redirector_test->expected_configuration['url'] : '',
    ));
  }
}
