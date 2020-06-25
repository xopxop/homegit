#!/usr/bin/php
<?php
$file = fopen("/var/run/utmp", "rb");
fseek($file, 768);
date_default_timezone_set("Europe/Moscow");
while (!feof($file))
{
	$data = fread($file, 384);
	if (strlen($data) == 384)
	{
		$data = unpack("itype/ipid/a32terminal/iterminalid/a32username/a256hostname/iterminalstatus/iexitstatus/isession/    /ipid/itype/itime", $data);
		if ($data['type'] == 7)
		{
			echo trim($data['user']) . " ";
			echo trim($data['line']) . "  ";
			$time = date("M d H:i", $data['time']);
			echo $time . "\n";
		}
	}
}
?>