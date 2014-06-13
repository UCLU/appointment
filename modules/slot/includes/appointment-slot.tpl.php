<?php
/**
 * @file
 * Default theme implementation to display an appointment slot.
 */
?>
<div id="appointment-slot-<?php print $slot->slot_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page && !empty($content['field_appointment_time'])): ?>
    <h2><?php print render($content['field_appointment_time']); ?></h2>
  <?php elseif (!$page && $label): ?>
    <h2><?php print $label; ?></h2>
  <?php endif; ?>

  <div class="content">
    <?php print render($content); ?>
  </div>

</div>
