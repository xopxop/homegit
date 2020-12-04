<?php

class HomePage extends Controller {
	public function __construct() {
		parent::__construct();
	}

	public function __destruct() {
		parent::__destruct();
	}

	public function index() {
		$this->_model = $this->loadModel('homepage');
		$this->_view = $this->loadView('homepage/index');
	}
}