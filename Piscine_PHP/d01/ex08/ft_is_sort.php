<?PHP

function ft_is_sort($tab) {
	$sorted_tab = $tab;
	sort($sorted_tab);
	// print_r($tab);
	// print_r($sorted_tab);
	return ($tab == $sorted_tab);
}

?>