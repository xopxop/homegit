<?php
include("db.class.php");

if (isset($_POST['createAccount'])) {
	$firstName = $_POST['firstName'];
	$lastName = $_POST['lastName'];
	$email = $_POST['email'];
	$username = $_POST['username'];
	$password = $_POST['password'];

	//need to be hashed password
	DB::query("INSERT INTO users VALUES (firstName, lastName, email, username, hassed_password)", array('firstName' => $firstName, 'lastName' => $lastName, 'email' => $email, 'username' => $username, 'hassed_password' => $password));
	echo "Success";
}

?>
<h1>Register</h1>
<form action="create-account.php" method="post" >
	<input type="text" name="firstName" value="" placeholder="your first name" required /><br/>
	<input type="text" name="lastName" value="" placeholder="your last name" required /><br/>
	<input type="email" name="email" value="" placeholder="someone@somesite" required /><br/>
	<input type="text" name="username" value="" placeholder="username..." required /><br/>
	<input type="password" name="password" value="" placeholder="password..." required /><br/>
	<input type="submit" name="createAccount" value="Create Account" />
</form>