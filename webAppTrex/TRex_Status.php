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
  <link rel="stylesheet" href="css/slider.css">
  <script src="./js/vendor/modernizr.js"></script>
  <script src="./js/vendor/jquery.js"></script> 
  <script src="./js/vendor/fastclick.js"></script>
  <script src="./js/foundation/foundation.js"></script>
  <script src="./js/foundation/foundation.alert.js"></script>
	<title>TRex Status</title>
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
      <li><a href="Pi_Status.php">Pi Status</a></li> 
    </ul>
    <!-- Left Nav Section -->
    <ul class="left">
    </ul>
  </section>
</nav>
<!-- Navbar end -->

<h1>Controller and status of the TRex controller</h1>

<div data-alert class="alert-box">
  <?php 

  $sock_rex = new MySocket('10.176.40.199','9999');//hier ip adres en port aanpassen

  $toSend = '{"trex_status":"true"}';
  $sock_rex->send($toSend);
  $obj = $sock_rex->get();

  $err = 0;
  $bat = 0;
  $mot = 0;
  $enc = 0;

  $obj = json_decode($obj);
  $err = $obj->{'error-flags'};
  $bat = $obj->{'battery-voltage'};
  $mot = $obj->{'moter-current'};
  $enc = $obj->{'encoder-count'};

  ?>
  <a href="#" class="close">&times;</a> 
</div>

<h2 class="subheader">TRex controller</h2>

<table>
  <thead>
    <tr>
      <th>
        Error flags
      </th>
      <th>
        Battery voltage
      </th>
      <th>
        Moter current
      </th>
      <th>
      	Encoder count
      </th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>
        <?php echo $err ?>
      </td>
      <td>
        <?php echo $bat ?>
      </td>
      <td>
        <?php echo $mot ?>
      </td>
      <td>
        <?php echo $enc ?>
      </td>
    </tr>
  </tbody>
</table>

<h2 class="subheader">TRex controller</h2>
<h3 class="subheader">Left engine</h3>

<input id="leftSlider" type="range"  min="-200" max="200" value="0" step="20" onchange="valueChange(this.value,rightSlider.value)"/>
<span id="rangeLeft">0</span>

<h3 class="subheader">Right engine</h3>

<input id="rightSlider" type="range"  min="-200" max="200" value="0" step="20" onchange="valueChange(leftSlider.value,this.value)"/>
<span id="rangeRight">0</span>

<div id="aaa"></div>
<div id="footer">
         Created by P. Desender
</div>
</body>
</html>
<script type="text/javascript">
  function valueChange(leftValue,rightValue)
  {
    document.getElementById("rangeLeft").innerHTML=leftValue;
    document.getElementById("rangeRight").innerHTML=rightValue;
    $.ajax({
      type: "POST",
      url: "ajax.php",
      data: { leftEngine: ""+leftValue, rightEngine: ""+rightValue }
    })
  }
</script>
  