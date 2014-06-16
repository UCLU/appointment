<?php
/**
 * @file
 * Default theme implementation to display an appointment slot.
 */
?>
<div id="appointment-slot-<?php print $slot->slot_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($teaser && !empty($content['field_appointment_time'])): ?>
    <h2><a href="<?php print $url; ?>"><?php print render($content['field_appointment_time']); ?></a></h2>
  <?php elseif ($teaser && $label): ?>
    <h2><a href="<?php print $url; ?>"><?php print $label; ?></a></h2>
  <?php endif; ?>

  <div class="content">
    <?php print render($content); ?>
  </div>

</div>
