#!/usr/bin/php
<?PHP

if ($argc == 2) {
	$tab = file($argv[1]);
	foreach ($tab as $elem) {
		$pattern = "/(<a )(.*?)(>)(.*)(<\/a>)si/";
		$callback;
		$subject;
		$newElem = preg_replace_callback($pattern, 
			function ($matches) {
				return $matches[1].$matches[2].$matches[3].strtoupper($matches[4]).$matches[5];
			},
			$elem
		);
		echo "New: $newElem";
		echo "$elem";
	}
}

?>