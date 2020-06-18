<?PHP

if ((isset($_POST['login'])) && ($_POST['login'] != "") && (isset($_POST['oldpw'])) && ($_POST['oldpw'] != "") && (isset($_POST['newpw'])) && ($_POST['newpw'] != "") && (isset($_POST['submit'])) && ($_POST['submit'] === "OK")) {
	$account = unserialize(file_get_contents("../htdocs/private/passwd"));
	$modified = false;
	if ($account) {
		foreach ($account as $key => $elem) {
			if ($elem['login'] === $_POST['login'] && $elem['passwd'] === hash("whirlpool", $_POST['oldpw'])) {
				echo $account['key']['passwd']."\n";
				echo hash("whirlpool", $_POST['newpw'])."\n";
				$account['key']['passwd'] = hash("whirlpool", $_POST['newpw']);
				echo $account['key']['passwd']."\n";
				file_put_contents("../htdocs/private/passwd", serialize($account));
				$modified = true;
				break ;
			}
		}
	}
	echo ($modified == true) ? "OK\n" : "ERROR\n";
}
else
	echo "ERROR\n";
?>