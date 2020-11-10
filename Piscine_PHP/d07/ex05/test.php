<?php

require_once 'IFighter.class.php';
require_once 'NightsWatch.class.php';

class JohnSnow implements IFighter {
	public function fight() {
		print( "* looses his wolf on the enemy, and charges with courage *" . PHP_EOL );
	}
}

class MaesterAemon {
	public function sendRavens() {
		print("* sends a raven carrying an important message *" . PHP_EOL);
	}
}

class SamwellTarly implements IFighter {
	public function fight() {
		print( "* flees, finds a girl, grows a spine, and defends her to the bitter end *" . PHP_EOL );
	}
}

$js = new JohnSnow();
$st = new SamwellTarly();
$ma = new MaesterAemon();
$nw = new NightWatch();

$nw->recruit($js);
$nw->recruit($ma);
$nw->recruit($st);
$nw->fight();

?>