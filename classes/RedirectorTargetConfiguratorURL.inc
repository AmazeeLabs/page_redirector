<?php

/**
 * @file
 *  Class for configuring the target URL.
 */

class RedirectorTargetConfiguratorURL implements RedirectorTargetConfiguratorInterface {

  /**
   * @see RedirectorTargetConfiguratorInterface::getFormElements()
   */
  public static function getFormElements($redirector_test = NULL) {
    return array('url' => array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('The URL of the request.'),
      '#default_value' => !empty($redirector_test->target_configuration) ? $redirector_test->target_configuration['url'] : '',
    ));
  }

  /**
   * (non-PHPdoc)
   * @see RedirectorTargetConfiguratorInterface::configureRequest()
   */
  public static function configureRequest($curl, $redirect_test) {
    // Sets the url of the target.
    curl_setopt($curl, CURLOPT_URL, $redirect_test->target_configuration['url']);
  }
}
