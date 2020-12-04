<?php

class View {
	public function __construct($view) {
		require_once('app/views/header.php');
		require_once('app/views/' . $view . ".php");
		require_once('app/views/footer.php');
	}
}