#!/usr/bin/php
<?PHP

// Example 1:
// "^" : the begining of the string
// "$" : the end of the string
// "[]": posible choice in the square brackets, example [oi], [0-9], [a-m]
// "+" : last character can be repeating once or more
// "*" : character can be there 0 time or several times, example "tti" => "true" while with '+' then "tti" => "false"
// "?" :
// {} : exactly repeatation
// [^sth] : anything but sth inside the square bracket

$nb = preg_match("/t([io])t\1/", "toti");  // ===> This one need to find more info because he didnt want to

echo "$nb\n"

?>