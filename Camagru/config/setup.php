<?php
require_once('database.php');

/* Create database and its admin */
try {
	$dbh = new PDO("mysql:host=localhost", $DB_ROOT_USER, $DB_ROOT_PASSWORD, $DB_OPTIONS);
	// create database
	$sql = "CREATE DATABASE " . $DB_NAME . "";
	$dbh->exec($sql);
	// creat user
	$sql = "CREATE USER '" . $DB_USER . "'@'" . $DB_HOST . "' IDENTIFIED BY '" . $DB_PASSWORD . "'";
	$dbh->exec($sql);
	// // grant the privilege on db_camagru to this user
	$sql = "GRANT ALL ON " . $DB_NAME . ".* TO '" . $DB_USER . "'@'" . $DB_HOST . "'";
	$dbh->exec($sql);
	$dbh = null;
} catch (PDOException $e) {
	die("Setup failed Unable to create database and its admin: " . $e->getMessage());
}

/* log into new user */
try {
	$dbh = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD, $DB_OPTIONS);
} catch (PDOException $e) {
	die("Setup failed Unable to log into with new user : " . $e->getMessage());
}

/*create user table */
try {
	$sql = "CREATE TABLE users (
			id INT UNSIGNED AUTO_INCREMENT,
			firstName VARCHAR(30),
			lastName VARCHAR(30),
			email VARCHAR(50),
			username VARCHAR(30),
			profilePicture VARCHAR(255),
			hassed_password VARCHAR(255),
			PRIMARY KEY (id)
			)";
	$dbh->exec($sql);
} catch (PDOException $e) {
	die ("Setup failed Unable to create user table :" . $e->getMessage());
}

/* create images table */
try {
	$sql = "CREATE TABLE images (
		id INT UNSIGNED AUTO_INCREMENT,
		userId INT UNSIGNED,
		creationDate DATETIME,
		filePath VARCHAR(255),
		PRIMARY KEY (id)
		)";
	$dbh->exec($sql);
} catch (PDOException $e) {
	die ("Setup failed Unable to create images table :" . $e->getMessage());
}

/* create comment table */
try {
	$sql = "CREATE TABLE comments (
		id INT UNSIGNED AUTO_INCREMENT,
		userId INT UNSIGNED,
		imageId INT UNSIGNED,
		creationDate DATETIME,
		content VARCHAR(255),
		PRIMARY KEY (id)
		)";
	$dbh->exec($sql);
} catch (PDOException $e) {
	die ("Setup failed Unable to create comment table :" . $e->getMessage());
}

/* create likes table */
try {
	$sql = "CREATE TABLE likes (
		id INT UNSIGNED AUTO_INCREMENT,
		senderId INT UNSIGNED,
		receiverId INT UNSIGNED,
		imageId INT UNSIGNED,
		creationDate DATETIME,
		PRIMARY KEY (id)
		)";
	$dbh->exec($sql);
} catch (PDOException $e) {
	die ("Setup failed Unable to create likes table :" . $e->getMessage());
}

/* disconnect database */
$dbh = null;

/* redirect to public root */
header("Location: ../public/index.php");
exit();

?>