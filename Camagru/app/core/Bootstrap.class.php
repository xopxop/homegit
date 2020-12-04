<?php

class Bootstrap {
	protected $_controller = "homepage";
	protected $_method = "index";
	protected $_params = [];

	public function __construct() {
		// set the protected url
		$url = $this->_parseUrl();

	
		// load new controller
		if (isset($url[0])) {
			if (file_exists('app/controllers/' . $url[0]. '.class.php')) {
				$this->_controller = $url[0];
				unset($url[0]);
			} else {
				$this->_loadError();
			}
		}
		
		require_once('app/controllers/' . $this->_controller. '.class.php');
		// load new method
		if (isset($url[1])) {
			if (method_exists($this->_controller, $url[1])) {
				$this->_method = $url[1];
				unset($url[1]);
			} else {
				$this->_loadError();
			}
		}

		// $this->_params
		call_user_func_array([new $this->_controller, $this->_method], $this->_params);
	}

	private function _parseUrl() {
		if(isset($_GET['url'])) {
			return $url = explode('/', filter_var(rtrim($_GET['url'], '/'), FILTER_SANITIZE_URL));
		}
	}

	private function _loadError() {
		call_user_func_array('error404', 'index', []);
		die();
	}
}