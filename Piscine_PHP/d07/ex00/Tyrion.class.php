<?php

class Tyrion extends Lannister {
	public function __construct () {
		print( 'My name is Tyrion' . PHP_EOL );
		return ;
	}
	public function __destruct () {
		return ;
	}
	public function getHeight () {
		return "Short";
	}
	public function roar() {
		return "Hear me roar";
	}
}

?>