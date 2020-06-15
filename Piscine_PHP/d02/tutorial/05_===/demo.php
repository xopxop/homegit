#!/usr/bin/php
<?PHP

/* Example 1: It will display KO
if ("Hello" == "World")
	echo "OK\n";
else
	echo "KO\n";
*/

/* Example 2: It will display OK, why? because it will evaluate as number, however at the second parameter, "World" is a string and its number value is 0 => equal
if (0 == "World")
	echo "OK\n";
else
	echo "KO\n";
*/

/* Example 3: correct display
if (0 === "World")
	echo "OK\n";
else
	echo "KO\n";
*/

/* Example 4: it will display Found
$my_tab = array("zero", "one", "two");

if (array_search("one", $my_tab))
	echo "Found\n";
*/

/* Example 5: It will not display anything, why? because it array return is an index so, it will return index 0, and it will stupidly return false
$my_tab = array("zero", "one", "two");

if (array_search("zero", $my_tab))
	echo "Found\n";
*/

$my_tab = array("zero", "one", "two");

if (array_search("zero", $my_tab) !== FALSE)
	echo "Found\n";

?>