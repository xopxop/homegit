<?PHP
session_start();

include 'auth.php';
if ($_GET['login'] != NULL && $_GET['passwd'] != NULL)
{
	if (auth($_GET['login'], $_GET['passwd']) == true)
	{
		$_SESSION['loggued_on_user'] = $_GET['login'];
		echo "<html><body>";
		echo "<iframe name=\"chat\" src=\"char.php\" width=\"100%\" height=\"550px\"></iframe>";
		echo "<iframe name=\"speak\" src=\"speak.php\" width=\"100%\" height=\"50px\"></iframe>";
		echo "</div></body></html>";
	}
	else
		echo "ERROR" . PHP_EOL;
}
else
	echo "ERROR" . PHP_EOL;

?>
