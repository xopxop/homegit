<?php

class Targaryens {
	protected function _resistsFire() {
		return false;
	}
	public function fireTest() {
		if ($this->_resistsFire())
			return "emerges naked but unharmed";
		else
			return "burns alive";
	}
}

?>