#!/usr/bin/php
<?php
    date_default_timezone_set('Europe/Helsinki');
    $file = fopen("/var/run/utmp", 'r');
    $i = 0;
    $who = [];
    while ($str = fread($file, 384))
    {
		$tab = unpack("itype/i/a32tty/i/a32login/a256/i/i/i/Itime", $str);
        if ($tab['type'] == 7)
        {
            $time = strftime("%b %e %R", $tab['time']);
            array_push($who , str_pad($tab['login'], 8, " ") . " " . str_pad($tab['tty'], 8, " ") . " " . $time);
		}
		// $i = $i + 628;
		// echo $i . "\n";
    }
    sort($who);
    foreach ($who as $value)
        echo "$value\n";
?>