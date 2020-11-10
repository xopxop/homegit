<?php

require_once 'House.class.php';

class Martell extends House {
	protected function getHouseName() {
		return "Martell";
	}
	protected function getHouseCastle() {
		return "Sunspear";
	}
	protected function getFamilyMotto() {
		return "Unbowed, Unbent, Unbroken";
	}
}

?>