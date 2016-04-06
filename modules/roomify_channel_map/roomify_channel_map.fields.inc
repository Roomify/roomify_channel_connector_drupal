<?php

/**
 * Add Default Rate Price field.
 */
function roomify_rate_add_default_rate_field($type_bundle) {
  field_info_cache_clear();

  // "rate_default_rate" field.
  if (field_read_field('rate_default_rate') === FALSE) {
    $field = array(
      'field_name' => 'rate_default_rate',
      'type' => 'commerce_price',
      'cardinality' => 1,
      'locked' => 1,
    );
    field_create_field($field);
  }

  field_cache_clear();

  // "rate_default_rate" field instance.
  if (field_read_instance('roomify_rate', 'rate_default_rate', $type_bundle) === FALSE) {
    $instance = array(
      'field_name' => 'rate_default_rate',
      'entity_type' => 'roomify_rate',
      'bundle' => $type_bundle,
      'description' => '',
      'label' => 'Default Rate',
      'required' => 1,
      'widget' => array(
        'active' => 1,
        'module' => 'commerce_price',
        'settings' => array(
          'currency_code' => 'default',
        ),
        'type' => 'commerce_price_full',
      ),
    );
    field_create_instance($instance);
  }
}

/**
 * Add "Event type" reference field.
 */
function roomify_rate_add_event_type_reference_field($type_bundle) {
  field_info_cache_clear();

  // "rate_event_type_reference" field.
  if (field_read_field('rate_event_type_reference') === FALSE) {
    $field = array(
      'field_name' => 'rate_event_type_reference',
      'type' => 'entityreference',
      'cardinality' => 1,
      'locked' => 1,
      'settings' => array(
        'target_type' => 'bat_event_type',
      ),
    );
    field_create_field($field);
  }

  field_cache_clear();

  // "rate_event_type_reference" field instance.
  if (field_read_instance('roomify_rate', 'rate_event_type_reference', $type_bundle) === FALSE) {
    $instance = array(
      'field_name' => 'rate_event_type_reference',
      'entity_type' => 'roomify_rate',
      'label' => 'Event type',
      'bundle' => $type_bundle,
      'required' => FALSE,
      'widget' => array(
        'type' => 'entityreference_autocomplete',
      ),
    );
    field_create_instance($instance);
  }
}

