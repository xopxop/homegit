#!/usr/bin/php
<?php
    date_default_timezone_set('Europe/Helsinki');
    $file = fopen("/var/run/utmpx", 'r');
    $i = 0;
    $who = [];
    while ($str = fread($file, 628))
    {
		$tab = unpack("A256login/A4/A32tty/i/itype/Itime/i16", $str);
		echo sizeof($tab) . PHP_EOL;
        // if ($i >= 2 * 628 && $tab['type'] == 7)
        // {
            $time = strftime("%b %e %R", $tab['time']);
            array_push($who , str_pad($tab['login'], 8, " ") . " " . str_pad($tab['tty'], 8, " ") . " " . $time);
		// }
		// $i = $i + 628;
		// echo $i . "\n";
    }
    sort($who);
    foreach ($who as $value)
        echo "$value\n";
?>
