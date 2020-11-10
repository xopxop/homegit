<?php

require_once 'Daenerys.class.php';
require_once 'Viserys.class.php';

$daenerys = new Daenerys();
$viserys = new Viserys();

print( "Viserys " . $viserys->fireTest() . PHP_EOL );
print( "Daenerys " . $daenerys->fireTest() . PHP_EOL );

?>