#!/usr/bin/php
<?PHP


/* Example 1:
eval("echo 'Hello World';");
*/

// Example 2: it will evaluate the input, if the user input is dangerous like "rm -f ~/something", then it will not let this code execute
$myvar = fgets(STDIN);

eval($myvar);

?>