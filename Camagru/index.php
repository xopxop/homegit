<?php

require_once('app/config/constants.php');
require_once('app/config/database.php');

function myAutoLoader($class) {
	require_once('app/core/' . $class . '.class.php');
}

spl_autoload_register('myAutoLoader');

$app = new Bootstrap();