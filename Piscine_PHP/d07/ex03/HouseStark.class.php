<?php

require_once 'House.class.php';

class Stark extends House {
	protected function getHouseName() {
		return "Stark";
	}
	protected function getHouseCastle() {
		return "Winterfell";
	}
	protected function getFamilyMotto() {
		return "Winter is coming";
	}
}

?>