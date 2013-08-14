<?php

/**
 * PayPal Chained Payment additions to default commerce views.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function commerce_paypal_chained_views_default_views_alter(&$views) {
  if (isset($views['commerce_payment_order'])) {
    // Add our receiver email address field into this view
    $views['commerce_payment_order']->display['default']->display_options['fields']['field_chained_receiver_email'] = array(
      'id' => 'field_chained_receiver_email',
      'table' => 'field_data_field_chained_receiver_email',
      'field' => 'field_chained_receiver_email',
      'element_type' => '0',
      'element_label_colon' => FALSE,
      'element_wrapper_type' => '0',
      'element_default_classes' => FALSE,
      'field_api_classes' => TRUE,
    );
    // Pull the operations column out and re-append it as the last column in
    // this view.
    $operations = $views['commerce_payment_order']->display['default']->display_options['fields']['operations'];
    unset($views['commerce_payment_order']->display['default']->display_options['fields']['operations']);
    $views['commerce_payment_order']->display['default']->display_options['fields']['operations'] = $operations;
  }
}
