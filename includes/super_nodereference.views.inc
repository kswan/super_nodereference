<?php
// $Id:

function super_nodereference_views_plugins() {
  $plugins = array(
    'module' => 'super_nodereference', // This just tells our themes are elsewhere.
    'display' => array(
      'super_nodereference_references' => array(
        'path' => drupal_get_path('module', 'super_nodereference') . '/includes',
        // Those strings are not translated for now.
        // We'll need to change that if / when we remove 'no ui'
        'title' => 'Simple - for reference fields', // TODO: better name ? (currently not displayed anyway)
        'help' => 'Destination-agnostic display. Mostly useful for programmatic views.',
        'parent' => 'content_references',
        'handler' => 'super_nodereference_plugin_display_references',
        'no ui' => TRUE, // Programmatic use only.
        'uses hook menu' => FALSE,
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'accept attachments' => FALSE,
      ),
    )
  );
  return $plugins;
}
