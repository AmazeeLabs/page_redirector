<?php

/**
 * @file
 *  Class for configuring the target browser language.
 */

class RedirectorTargetConfiguratorBrowserLanguage implements RedirectorTargetConfiguratorInterface {

  /**
   * @see RedirectorTargetConfiguratorInterface::getFormElements()
   */
  public static function getFormElements($redirector_test = NULL) {
    return array('browser_language' => array(
      '#type' => 'textfield',
      '#title' => t('Browser language'),
      '#description' => t('The language code to be used in browser.'),
      '#default_value' => !empty($redirector_test->target_configuration) ? $redirector_test->target_configuration['browser_language'] : ''
    ));
  }

  /**
   * (non-PHPdoc)
   * @see RedirectorTargetConfiguratorInterface::configureRequest()
   */
  public static function configureRequest($curl, $redirect_test) {
    // @todo: this will set the language of the browser.
    curl_setopt($curl, CURLOPT_HTTPHEADER, array('Accept-Language: ' . $redirect_test->target_configuration['browser_language']));
  }
}
