#!/usr/bin/php
<?PHP

/* Example 1:

$tab = file("data.csv");

foreach ($tab as $elem)
{
	echo "$elem";
}

*/

/* Example 2:

$fd = fopen("data.csv", "r");

while ($line = fgets($fd))
{
	echo "$line";
}

fclose($fd);

*/

$fd = fopen("data.csv", "r");

while ($tab = fgetcsv($fd, 0, ";"))
{
	print_r($tab);
}

fclose($fd);

?>