$Id:$

Description
===========
The super_nodereference module provides a very flexible method of using a 
field that links to another node.  This module is based on the CCK
nodereference module and integrates with CCK, but adds some significant 
flexibility.

Improvements compared to CCK nodereference
==========================================
- super_nodereference fields can be configured to link to any field ("primary
  field") on the referenced node.  The CCK nodereference field is hard coded 
  to the node title.
- super_nodereference fields offer very flexible autocomplete options.  The
  referenced node can be looked up using (1) a standard sql query on the 
  "primary field", (2) a preconfigured view filtered by the "primary field",
  or (3) a preconfigured view with an exposed filter.  The CCK nodereference
  field doesn't recognize exposed filters.
- super_nodereference fields offer the option to store plain text if a
  matching node is not found.  CCK nodereference does not offer this option.

Limitations compared to CCK nodereference
=========================================
super_nodereference currently only offers the autocomplete widget.

Why not improve CCK nodereference?
==================================
The CCK nodereference module is in use on thousands of sites, therefore the 
maintainers are not able to accept significant changes in functionality.  
There is no plan for another major version for Drupal 6 (CCK 6.x-3.x is 
strictly allowing only one new feature).  I submitted a patch with part
of the functionality in super_nodereference to the CCK issue queue and the
CCK maintainers thought it should not be part of CCK 
(http://drupal.org/node/167809#comment-1709748).
