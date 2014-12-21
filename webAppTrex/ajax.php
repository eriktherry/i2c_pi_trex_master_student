<?php 
error_reporting(E_ALL);
ini_set('display_errors', '1');
require_once 'MySocket.php'
 
 $sock_rex = new MySocket('10.176.40.199','9999');//hier ip adres en port aanpassen
 $toSend = "{\"leftEngine\": \"".$_POST['leftEngine']."\",\"rightEngine\":\"".$_POST['rightEngine']."\"}";
 $sock_rex->send($toSend);
?>