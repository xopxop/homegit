#!/usr/bin/php
<?php
/*
	documentation:
	https://man7.org/linux/man-pages//man5/utmp.5.html
	https://github.com/libyahttps://man7.orghttps://man7.org/linux/man-pages//man5/utmp.5.html/linux/man-pages//man5/utmp.5.htmll/dtformats/blob/master/documentation/Utmp%20login%20records%20format.asciidoc
	Note :	utmp struct can vary between OSs
			This program is only for Linux, and writen and tested on Ubuntu 20.04LTS
			The format of utmp struct arcoding to the document is for Linux libc 6 utmp
			while unpacking a block of 384 bytes, the format used only to grap:
				+ Type of login
				+ Terminal
				+ Username
				+ Timestamp
			with the range from "Type of login" to "Timestamp"
	Incorrect part: On Ubuntu, the Timestamp for user is incorrect only
	Note2: The file "who.php" is only for MacOS (correct)
					"who2.php" is for Linux		(partly correct, not included Timestamp)
*/
    date_default_timezone_set('Europe/Helsinki');
    $file = fopen("/var/run/utmp", 'r');
    $i = 0;
    $who = [];
    while ($str = fread($file, 384))
    {
		$tab = unpack("itype/i/a32tty/i/a32login/a256/i/i/i/Itime", $str);
        if ($tab['type'] == 7)
        {
			echo $tab['time'] . "\n";
            $time = strftime("%Y-%m-%d: %H:%M", $tab['time']);
            array_push($who , str_pad($tab['login'], 8, " ") . " " . str_pad($tab['tty'], 8, " ") . " " . $time);
		}
    }
    sort($who);
    foreach ($who as $value)
        echo "$value\n";
?>
