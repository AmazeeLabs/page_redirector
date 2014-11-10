<?php

/**
 * @file
 *  Interface for the TargetConfigurator classes.
 */

interface RedirectorTargetConfiguratorInterface {

  public static function getFormElements($redirect_test = NULL);

  /**
   * Configures (prepares) the request before it is being sent.
   *
   * @param object $curl
   *  The curl object used for request.
   *
   * @param object $redirect_test
   *  The redirect test object.
   */
  public static function configureRequest($curl, $redirect_test);
}
