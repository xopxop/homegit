<?PHP
session_start();

// if (!isset($_SESSION))
// 	session_start();
// else
// {
// 	session_destroy();
// 	session_start();
// }
// echo "HERE\n";
include 'auth.php';
if ($_GET['login'] != NULL && $_GET['passwd'] != NULL)
{
	if (auth($_GET['login'], $_GET['passwd']))
	{
		$_SESSION['loggued_on_user'] = $_GET['login'];
		echo "OK" . PHP_EOL;
	}
	else
		echo "ERROR" . PHP_EOL;
}
else
	echo "ERROR" . PHP_EOL;

?>