<?php

/**
 * @file
 *  Class for configuring the source URL.
 */

class RedirectorSourceConfiguratorURL implements RedirectorSourceConfiguratorInterface {

  /**
   * @see RedirectorSourceConfiguratorInterface::getFormElements()
   */
  public static function getFormElements($redirector_test = NULL) {
    return array('url' => array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('The URL of the request.'),
      '#default_value' => !empty($redirector_test->source_configuration) ? $redirector_test->source_configuration['url'] : '',
    ));
  }
}
