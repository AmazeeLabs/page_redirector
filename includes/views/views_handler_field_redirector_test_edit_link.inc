<?php

/**
 * @file
 *  Views field hanlder for the edit link.
 */

class views_handler_field_redirector_test_edit_link extends views_handler_field_redirector_test_link {

  function render_link($entity, $values) {
    // @todo: we should reactivate this when we implement an access callback.
    //if (entity_access('update', 'redirector_test', $entity)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "admin/config/system/redirector/edit/$entity->tid";
      $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
      return $text;
    //}
  }
}