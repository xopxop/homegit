#!/usr/bin/php
<?PHP

function ft_split($string) {
	return (array_filter(preg_split('/\s+/', trim($string))));
}

if ($argc > 1) {
	$my_array = ft_split($argv[1]);
	print_r($my_array);
	$size = count($my_array);
	echo $my_array[0] . PHP_EOL;
	if ($size > 1)
		for ($i = 1; $i < $size; $i++)
			echo "$my_array[$i] ";
	echo $my_array[0] . PHP_EOL;
}

?>