<!DOCTYPE html>  
<html>
	<style>
		td {
			font-size: 50px;
		}
	</style>  
<body style="text-align: center;">
<table align = "center" border = "10" cellpadding = "3" cellspacing = "2">  
<tr>  
<td> ID </td>  
<td> PPM </td>  
<td> DateTime </td>  
</tr>  
<?php

$hostname = "localhost"; 
$username = "root"; 
$password = ""; 
$database = "mq7_data"; 

$conn = mysqli_connect($hostname, $username, $password, $database);

if (!$conn) { 
	die("Connection failed: " . mysqli_connect_error()); 
} 

echo "<h1>MQ7 Database</h1><br>"; 
$sql = "SELECT * FROM mq7";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
	echo "<tr>";  
	echo "<td>".$row["id"]."</td>";  
	echo "<td>".$row["ppm"]."</td>";  
	echo "<td>".$row["datetime"]."</td>";  
	echo "</tr>";  
  }
} else {
  echo "0 results";
}


	if (mysqli_query($conn, $sql)) { 
		echo "\nNew record"; 
	} else { 
		echo "Error: " . $sql . "<br>" . mysqli_error($conn); 
	}

if(isset($_POST["ppm"])) {
	echo "DATA SAVED";

	$p = $_POST["ppm"];

	$sql = "INSERT INTO mq7 (ppm) VALUES (".$p.")"; 

	if (mysqli_query($conn, $sql)) { 
		echo "\nNew record created successfully"; 
	} else { 
		echo "Error: " . $sql . "<br>" . mysqli_error($conn); 
	}
}
$conn->close();

?>
</table>  
</body>  
</html>