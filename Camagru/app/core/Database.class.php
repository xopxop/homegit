<?php

class Database extends PDO {
	public function __construct($DB_DSN, $DB_USER, $DB_PASSWORD) {
		parent::__construct($DB_DSN, $DB_USER, $DB_PASSWORD);
	}
}