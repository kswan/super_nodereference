<?php
// $Id:?

/**
 * @file
 * Handler for 'super_nodereference_plugin_display_references' display.
 */

class super_nodereference_plugin_display_references extends content_plugin_display_references {

  function uses_exposed() {
    watchdog('test', 'super_nodereference_plugin_display_references: %value', array('%value' => var_export(FALSE, TRUE)));
    return TRUE;
  }


}