#!/usr/bin/php
<?PHP

function split($string) {
	return (array_filter(explode(' ', $string)));
}

if ($argc != 1) {
	$my_arr = [];
	for ($i = 1; $i < $argc; $i++) {
		$words = split($argv[$i]);
		foreach ($words as $elem)
			$my_arr[] = $elem;
	}
	print_r($my_arr);
	// sort($my_arr, SORT_REGULAR);
	// foreach ($my_arr as $elem)
	// 	echo "$elem\n";
}

?>