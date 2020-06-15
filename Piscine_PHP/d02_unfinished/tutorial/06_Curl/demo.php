#!/usr/bin/php
<?PHP

$c = curl_init("https://www.42.fr");

$str = curl_exec($c);

echo "$str";

?>