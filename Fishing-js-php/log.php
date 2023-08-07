<?php
$User = $_POST['username'];
$Pass = $_POST['password'];
$infoArray = array('Password' => $Pass, 'Username' => $User);
$Json = json_encode($infoArray);
$filename = fopen("data.json", "a");
fwrite($filename, $Json . "\n"); // اضافه کردن \n برای ایجاد خط جدید در هر ذخیره
fclose($filename);
?>

