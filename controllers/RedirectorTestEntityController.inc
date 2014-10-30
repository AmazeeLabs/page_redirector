<?php

/**
 * @file
 *  Controller class for the RedirectorTest Entity.
 */

class RedirectorTestEntityController extends DrupalDefaultEntityController implements EntityAPIControllerInterface{

  public function delete($ids) {
    db_delete('redirector_tests')->condition('tid', $ids)->execute();
  }

  // The next methods are not yet supported. We have to implement them.
/* (non-PHPdoc)
 * @see EntityAPIControllerInterface::invoke()
 */public function invoke($hook, $entity) {
    // TODO Auto-generated method stub
    }

/* (non-PHPdoc)
 * @see EntityAPIControllerInterface::save()
 */public function save($entity) {
    // TODO Auto-generated method stub
    }

/* (non-PHPdoc)
 * @see EntityAPIControllerInterface::create()
 */public function create(array $values = array()) {
    // TODO Auto-generated method stub
    }

/* (non-PHPdoc)
 * @see EntityAPIControllerInterface::export()
 */public function export($entity, $prefix = '') {
    // TODO Auto-generated method stub
    }

/* (non-PHPdoc)
 * @see EntityAPIControllerInterface::import()
 */public function import($export) {
    // TODO Auto-generated method stub
    }

/* (non-PHPdoc)
 * @see EntityAPIControllerInterface::buildContent()
 */public function buildContent($entity, $view_mode = 'full', $langcode = NULL) {
    // TODO Auto-generated method stub
    }

/* (non-PHPdoc)
 * @see EntityAPIControllerInterface::view()
 */public function view($entities, $view_mode = 'full', $langcode = NULL, $page = NULL) {
    // TODO Auto-generated method stub
    }

}
