<?php
class MySocket{
    function __construct($ip,$port){
        $this->ip = $ip;
        $this->port = $port;

        // error_reporting(E_ALL);

        echo "TCP/IP Connection<br>";
        echo "creating socket:...";
        $this->socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
        if ($this->socket === false) {
            echo "socket create failed: reason: " . socket_strerror(socket_last_error()) . "<br>";
        } else {
            echo "OK.<br>";
        }


        echo "Attempting to connect to '$ip' on port '$port'...";
    
        $result = socket_connect($this->socket, $ip, $port);
        if ($result === false) {
            echo "socket connection failed.\nReason: ($result) " . socket_strerror(socket_last_error($socket)) . "\n<br>";
        } else {
            echo "OK. Ready to send.\n<br>";
        }

        $this->out = '';
    }
    
    public function send($in){

        socket_write($this->socket, $in, strlen($in));

        //while ($out = socket_read($this->socket, 2048)) {
        //}

    }  
    public function get(){
            return $this->out;
    }
    public function closeSock(){
        echo "Closing socket...";
        socket_close($this->socket);
        echo "OK.\n\n";
    }

}
?>
