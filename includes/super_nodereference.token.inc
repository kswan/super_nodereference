<?php
// $Id:?

function super_nodereference_token_values($type, $items = NULL) {
  $item = $object[0];

  $field = content_fields($element['#field_name'], $element['#type_name']);
  $primary_field = _super_nodereference_potential_references($field, '', 'equals', array($item['nid']), 1);
  $default =  is_numeric($item['nid']) ? $primary_field : $item['value'];
  $title = is_numeric($item['nid']) ? _super_nodereference_title($item['nid']) : $item['value'];
  
  $tokens['nid']   = $item['nid'];
  $tokens['default']   = check_plain($default);
  $tokens['default-raw']   = $default;
  $tokens['title'] = $title ? check_plain($title) : '';
  $tokens['title-raw'] = $title;
  $tokens['link']  = isset($item['view']) ? $item['view'] : '';
  $tokens['path'] = is_numeric($item['nid']) ? url('node/' . $item['nid']) : '';
  $tokens['url'] = is_numeric($item['nid']) ? url('node/' . $item['nid'], array('absolute' => TRUE)) : '';

  return $tokens;
  
  
}

function super_nodereference_token_list($type = 'field') {
  $tokens = array();

  $tokens['super node reference']['nid']   = t('Referenced node ID');
  $tokens['super node reference']['default']   = t('Default field in referenced node');
  $tokens['super node reference']['default-raw']   = t('Default field in referenced node. WARNING - raw user input.');
  $tokens['super node reference']['title'] = t('Referenced node title');
  $tokens['super node reference']['title-raw'] = t('Referenced node unfiltered title. WARNING - raw user input.');
  $tokens['super node reference']['link']  = t("Formatted html link to the referenced node.");
  $tokens['super node reference']['path']  = t("Relative path alias to the referenced node.");
  $tokens['super node reference']['url']  = t("Absolute path alias to the referenced node.");

  return $tokens;
  
}