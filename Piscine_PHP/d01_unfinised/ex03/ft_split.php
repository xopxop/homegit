<?PHP

function ft_split($string) {
	$words = array_filter(preg_split('/\s+/', $string));
	sort($words, SORT_REGULAR);
	return ($words);
}

?>