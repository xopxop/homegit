<?php
require_once("private/functions.php");
require_once("config/database.php");

try {
	$dbh = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD, $DB_OPTIONS);
} catch (PDOException $e) {
	redirectTo("config/setup.php");
}
$dbh = null;
redirectTo("public/index.php");
?>