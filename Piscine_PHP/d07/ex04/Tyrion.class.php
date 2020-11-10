<?php

require_once 'Lannister.interface.php';

class Tyrion implements ILannister {
	public function sleepWith($name) {
		if (strtolower($name) === "jaime" || strtolower($name) === "cersei")
			print("Not even if I'm drunk !" . PHP_EOL );
		else
			print("Let's do this." . PHP_EOL );
	}
}

?>