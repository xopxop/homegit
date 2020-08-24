<?PHP
session_start();
if ($_SESSION['loggued_on_user'] == NULL)
	echo "ERROR" . PHP_EOL;
else {
	if ($_POST['msg'] != NULL) {
		if (!file_exists("../private"))
			mkdir("../private");
		if (!file_exists("../private/chat"))
			file_put_contents("../private/chat", NULL);
		$chat = unserialize("../private/chat");
		$fd = fopen("../private/chat", 'w');
		flock($fd, LOCK_EX);
		$data['time'] = time();
		$data['login'] = $_SESSION['loggued_on_user'];
		$data['msg'] = $_POST['msg'];
		$chat[] = $data;
		file_put_contents("../private/chat", serialize($chat));
		fclose($fd);
	}
}
?>