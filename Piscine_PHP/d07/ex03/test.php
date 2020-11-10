<?php

require_once 'HouseStark.class.php';
require_once 'HouseMartell.class.php';

$stark = new Stark();
$martell = new Martell();
$stark->announce();
$martell->announce();

?>