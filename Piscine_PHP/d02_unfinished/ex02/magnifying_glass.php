#!/usr/bin/php
<?PHP

if ($argc == 2) {
	$tab = file($argv[1]);
	foreach ($tab as $elem) {
		$callback;
		$subject;
		$elem = preg_replace_callback("/(<a href=)(.*?)(>)(.*?)(<\/a>)/", 
			function ($matches) {
				$elem2 = preg_replace_callback("/( title=\")(.*?)(\")/", function($matches) {
					return $matches[1].strtoupper($matches[2]).$matches[3];
				}, $matches[0]);
				$elem2 = preg_replace_callback("/(>)(.*?)(<)/", function($matches) {
					return $matches[1].strtoupper($matches[2]).$matches[3];
				}, $matches[0]);
				return $elem2;
			},
			$elem
		);
		echo $elem;
	}
}

?>