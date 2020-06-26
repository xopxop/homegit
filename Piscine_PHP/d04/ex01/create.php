<?PHP

function creatAccount($account) {
	$newAccount['login'] = $_POST['login'];
	$newAccount['passwd'] = hash("whirlpool", $_POST['passwd']);
	$account[] = $newAccount;
	file_put_contents("../htdocs/private/passwd", serialize($account));
}

if ((isset($_POST['login'])) && ($_POST['login'] != "") && (isset($_POST['passwd'])) && ($_POST['passwd'] != "") && (isset($_POST['submit'])) && ($_POST['submit'] === "OK")) {
	if (!file_exists("../htdocs")) {
		mkdir("../htdocs");
	}
	if (!file_exists("../htdocs/private")) {
		mkdir("../htdocs/private");
	}
	if (!file_exists("../htdocs/private/passwd")) {
		file_put_contents("../htdocs/private/passwd", NULL);
		chmod("./htdocs/private/passwd", 0777);
	}
	$account = unserialize(file_get_contents("../htdocs/private/passwd"));
	$exist = false;
	if ($account) {
		foreach ($account as $elem)
			if ($elem['login'] == $_POST['login']) {
				$exist = true;
				break ;
			}
	}
	if ($exist == false)
	{
		creatAccount($account);
		echo "OK\n";
	}
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";
?>