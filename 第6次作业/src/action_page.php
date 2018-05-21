<html>
<body>

debug messages begin <br>

<?php var_dump($_GET);
$job_name = $_GET['job_name'];
$cmd_line = $_GET['cmd_line'];
$max_retry_time = $_GET['max_retry_time'];
$time_out = $_GET['time_out'];
$image_id = $_GET['image_id'];
?> <br>

end <br>

your jobname is <?php echo $job_name; ?> <br>
command line is: <?php echo $cmd_line; ?> <br>
max retry time is: <?php echo $max_retry_time; ?> <br>
time limit is: <?php echo $time_out; ?> <br>
image id is: <?php echo $image_id; ?> <br>

debug messages begin <br>

<?php
echo "/var/www/a.out $job_name $cmd_line $max_retry_time $time_out $image_id";

echo "<br>";

echo `/var/www/a.out $job_name $cmd_line $max_retry_time $time_out $image_id`;

echo "<br>";

echo `pwd`;

echo "<br>";

system("/var/www/a.out $job_name $cmd_line $max_retry_time $time_out $image_id", $status);
 ?> <br>


end <br>

</body>
</html>
