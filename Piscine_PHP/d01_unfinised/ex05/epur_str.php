#!/usr/bin/php
<?PHP

function trimmedStr($str) {
	return (preg_replace('/\s+/', ' ', trim($str)));
}

if ($argc == 1)
	;
else if ($argc > 2)
	echo "One argument only!\n";
else
	echo trimmedStr($argv[1])."\n";

?>