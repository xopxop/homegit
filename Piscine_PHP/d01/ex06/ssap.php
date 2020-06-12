#!/usr/bin/php
<?PHP

function split($string) {
	return (array_filter(preg_split('/\s+/', $string)));
}

if ($argc != 1) {
	$my_arr = [];
	for ($i = 1; $i < $argc; $i++) {
		$words = split($argv[$i]);
		foreach ($words as $elem)
			$my_arr[] = $elem;
	}
	sort($my_arr, SORT_REGULAR);
	foreach ($my_arr as $elem)
		echo "$elem\n";
}

?>