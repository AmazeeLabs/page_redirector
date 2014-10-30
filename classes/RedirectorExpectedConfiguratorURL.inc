<?php

/**
 * @file
 *  Class for configuring the expected URL.
 */

class RedirectorExpectedConfiguratorURL implements RedirectorExpectedConfiguratorInterface {

  /**
   * @see RedirectorExpectedConfiguratorInterface::getFormElements()
   */
  public static function getFormElements($redirector_test = NULL) {
    return array('url' => array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('The URL of the returned result. Leave empty if not important.'),
      '#default_value' => !empty($redirector_test->expected_configuration) ? $redirector_test->expected_configuration['url'] : '',
    ));
  }
}
