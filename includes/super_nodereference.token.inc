<?php
// $Id$

/**
 * @file
 */

function super_nodereference_token_values($type, $object = NULL) {
  $tokens = array();
  if ($type == 'node') {
    $node = $object;
    // Prevent against invalid 'nodes' built by broken 3rd party code.
    if (isset($node->type)) {
      $type = content_types($node->type);
      $node->build_mode = 'token';
      $node->content = array();
      content_view($node);
      // The formatted values will only be known after the content has been rendered.
      drupal_render($node->content);
      content_alter($node);

      //$field_types = _content_field_types();
      foreach ($type['fields'] as $field) {
        if ($field['type'] == 'super_nodereference') {
          $items = $node->{$field['field_name']};
          $token_values = _super_nodereference_token_values($field, $items);
          foreach ($token_values as $token => $value) {
            $tokens[$field['field_name'] .'-'. $token] = $value;
          }
        }
      }
    }
  }
  return $tokens;
}
  
function _super_nodereference_token_values($field, $items) {
  $tokens = array();
  $item = $items[0];  
  if (!isset($item['nid'])) {
    $item += _super_nodereference_text_to_array($item['value']);
  }
  $primary_field = _super_nodereference_potential_references($field, '', 'equals', array($item['nid']), 1);
  $primary_field = array_shift($primary_field);
  $default =  is_numeric($item['nid']) ? $primary_field['title'] : $item['value'];
  $title = is_numeric($item['nid']) ? _super_nodereference_title($item['nid']) : $item['value'];
  $tokens['nid']   = $item['nid'];
  $tokens['default']   = check_plain($default);
  $tokens['default-raw']   = $default;
  $tokens['title'] = $title ? check_plain($title) : '';
  $tokens['title-raw'] = $title;
  $tokens['link']  = isset($primary_field['rendered']) ? $primary_field['rendered'] : '';
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