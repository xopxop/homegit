#!/usr/bin/php
<?PHP

function ft_replace($matches)
{
	$new = $matches[1].strtoupper($matches[2]).$matches[3];
	return ($new);
}

if ($argc == 2) {
	$line = file_get_contents($argv[1]);

	$hyperlink = "/(<a.*>)(.*?)(<\/a>)/i";

	$line = preg_replace_callback("$hyperlink",
	function($matches) {
		$matches[0] = preg_replace_callback("/(title=\")(.*)(\")/i", "ft_replace", $matches[0]);
		$matches[0] = preg_replace_callback("/(<a.*>)(.*)(<\/a>)/i", "ft_replace", $matches[0]);
		$matches[0] = preg_replace_callback("/(<a.*>)(.*)(<img)/i", "ft_replace", $matches[0]);
		return $matches[0];
	}, $line);
	echo $line;
}

?>