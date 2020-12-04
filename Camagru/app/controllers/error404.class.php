<?php

class Error404 extends Controller {

	public function __construct() {
		parent::__construct();
	}

	public function __destruct() {
		parent::__destruct();
	}

	public function index() {
		$this->view('error/index');
	}
}