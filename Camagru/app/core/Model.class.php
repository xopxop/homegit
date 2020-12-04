<?php

class Model {
	public function __construct() {
		$this->db = new Database($DB_DSN, $DB_USER, $DB_PASSWORD);
	}

	public function __destruct() {
		$this->db = null;
	}
}