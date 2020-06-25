#!/usr/bin/php
<?php
$file = fopen("/var/run/utmpx", "rb");
fseek($file, 1256);
date_default_timezone_set("Europe/Moscow");
while (!feof($file))
{
	$data = fread($file, 628);
	if (strlen($data) == 628) {
		$data = unpack("a256user/a4id/a32line/ipid/itype/itime", $data);
		$array[] = $data;
	}
}
ksort($array);
foreach($array as $line) {
	if ($line['type'] == 7)
	{
		echo trim($line['user']) . " ";
		echo trim($line['line']) . "  ";
		$time = date("M d H:i", $line['time']);
		echo $time . "\n";
	}
}
?>
