<?php

/**
 * @file
 *  Class for configuring the source browser language.
 */

class RedirectorSourceConfiguratorBrowserLanguage implements RedirectorSourceConfiguratorInterface {

  /**
   * @see RedirectorSourceConfiguratorInterface::getFormElements()
   */
  public static function getFormElements($redirector_test = NULL) {
    return array('browser_language' => array(
      '#type' => 'textfield',
      '#title' => t('Browser language'),
      '#description' => t('The language code to be used in browser.'),
      '#default_value' => !empty($redirector_test->source_configuration) ? $redirector_test->source_configuration['browser_language'] : ''
    ));
  }
}
