<?php

require_once('bar.php');

class Foo extends Bar {
	public function __construct() {
		parent::__construct();
		echo "This is Foo" . PHP_EOL;
	}
}

// $bar = new Bar();
$foo = new Foo();
