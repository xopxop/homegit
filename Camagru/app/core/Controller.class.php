<?php

class Controller {
	public function __construct() { }
	public function __destruct() { }

	public function loadModel($model) {
		require_once('app/models/' . $model . '_model.class.php');
		return new $model();
	}

	// what is data here
	// protected function view($view, $data = []) {
	// }

	public function loadView($view) {
		return new View($view);
	}
}