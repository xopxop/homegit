<?php

require_once 'Greyjoy.class.php';

class Theon extends Greyjoy {
	public function announceMotto() {
		print( $this->familyMotto . PHP_EOL );
		return ;
	}
}

?>