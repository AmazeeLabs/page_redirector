<?php

/**
 * @file
 *  Views field hanlder for the edit link.
 */

class views_handler_field_redirector_test_run_link extends views_handler_field_redirector_test_link {

  function render_link($entity, $values) {
    // @todo: we should reactivate this when we implement an access callback.
    //if (entity_access('update', 'redirector_test', $entity)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "admin/config/system/redirector/run/$entity->tid";
      $text = !empty($this->options['text']) ? $this->options['text'] : t('run');
      return $text;
    //}
  }
}