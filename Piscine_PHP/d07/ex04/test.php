<?php

require_once 'Tyrion.class.php';
require_once 'Jaime.class.php';

$jaime = new Jaime();
$tyrion = new Tyrion();

$jaime->sleepWith("TyrIon");
$jaime->sleepWith("Sansa");
$jaime->sleepWith("Cersei");
$tyrion->sleepWith("Jaime");
$tyrion->sleepWith("Sansa");
$tyrion->sleepWith("Cersei");

?>