<?php

abstract class House {
	abstract protected function getHouseName();
	abstract protected function getHouseCastle();
	abstract protected function getFamilyMotto();
	
	public function announce() {
		print( "House " . $this->getHouseName() . " of "
						. $this->getHouseCastle() . " : \""
						. $this->getFamilyMotto() . "\"" . PHP_EOL);
	}
}

?>