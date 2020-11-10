<?php

require_once 'Lannister.interface.php';

class Jaime implements ILannister {
	public function sleepWith($name) {
		if (strtolower($name) === "tyrion")
			print("Not even if I'm drunk !" . PHP_EOL );
		else if (strtolower($name) === "cersei")
			print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
		else
			print("Let's do this." . PHP_EOL );
	}
}

?>