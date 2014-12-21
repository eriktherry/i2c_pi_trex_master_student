<?php 
error_reporting(E_ALL);
ini_set('display_errors', '1');
require_once 'MySocket.php'
 ?>
<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" href="css/foundation.css">
  <link rel="stylesheet" href="css/footer.css">
  <script src="./js/foundation/foundation.alert.js"></script>
	<title>Pi Status</title>
</head>
<body>

<!-- Navbar begin -->
<nav class="top-bar" data-topbar role="navigation">
  <ul class="title-area">
    <li class="name">
      <h1><a href="index.php">Home</a></h1>
    </li>
    <li class="toggle-topbar menu-icon"><a href="#"><span>Menu</span></a></li>
  </ul>
  <section class="top-bar-section">
    <!-- Right Nav Section -->
    <ul class="right">
      <li><a href="TRex_Status.php">Trex</a></li>    
    </ul>
    <!-- Left Nav Section -->
    <ul class="left">
    </ul>
  </section>
</nav>
<!-- Navbar end -->

<div data-alert class="alert-box">
<?php 
$sock_PI = new MySocket('10.176.40.199','9999');//hier ip adres en port aanpassen

$toSend = '{"pi_status":"true"}';
$sock_PI->send($toSend);
$obj = $sock_PI->get();

$mac = 0;
$cpu = 0;
$free = 0;
$obj = json_decode($out);

$mac = $obj->{'mac-address'};
$cpu = $obj->{'cpu-temp'};
$free = $obj->{'free-memory'};
?>
</div>

<h1>Status of the Pi</h1>

<table>
  <thead>
    <tr>
      <th>
        MAC Address
      </th>
      <th>
        CPU temperatuur
      </th>
      <th>
        Free memory
      </th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>
        <?php echo $mac ?>
      </td>
      <td>
        <?php echo $cpu ?>
      </td>
      <td>
        <?php echo $free ?>
      </td>
    </tr>
  </tbody>
</table>

<div id="footer">
        Created by P. Desender, M. Braem and E. Therry
</div>

</body>
</html>