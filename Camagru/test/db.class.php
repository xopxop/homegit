<?php

class DB {
	private static function connect() {
		$pdo = new PDO("mysql:host=localhost;dbname=db_camagru;charset=utf8", "camagru", "camagru");
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		return $pdo;
	}

	public static function query($query, $params = []) {
		$stmt = self::connect()->prepare($query);
		$stmt->execute();
		$data = $stmt->fetchAll();
		return $data;
	}
}