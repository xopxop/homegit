<?php

class Lannister {
	public function __construct () {
		print( 'A Lannister is born !' . PHP_EOL );
		return ;
	}
	public function __destruct () {
		return ;
	}
}

require_once 'Tyrion.class.php';

$tyrion = new Tyrion();
print($tyrion->getHeight() . PHP_EOL );
print($tyrion->roar() . PHP_EOL );

?>