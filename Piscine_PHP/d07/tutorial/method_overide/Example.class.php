<?php
class ExampleA {
	public function __construct() {
		print( 'Constructor ExampleA called' . PHP_EOL );
		return ;
	}

	public function __destruct() {
		print( 'Destructor ExampleA called' . PHP_EOL );
		return ;
	}

	public function foo() {
		print( 'Function foo from class A' . PHP_EOL );
		return ;
	}
};

class ExampleB extends ExampleA {
	public function __construct() {
		parent::__construct();
		print( 'Constructor ExampleB called' . PHP_EOL );
		return ;
	}

	public function __destruct() {
		print( 'Destructor ExampleB called' . PHP_EOL );
		parent::__destruct();
		return ;
	}

	public function foo() {
		parent::foo();
		print( 'Function foo from class B' . PHP_EOL );
		return ;
	}
};

$instanceA = new ExampleA();
$instanceA->foo();
$instanceB = new ExampleB();
$instanceB->foo();

?>