<!-- xampp、phpmyadminを用いた場合の位置情報追加プログラム-->
<?php 
$user = "[phpmyadminのユーザ名]";
$pass = "[phpmyadminのパスワード]";

$lat = $_POST['lat'];
$lng = $_POST['lng'];

try {
    $dbh = new PDO('mysql:host=localhost;dbname=[gpsを入れたいデータベース名];charset=utf8', $user, $pass);
    $dbh->setAttribute(PDO::ATTR_EMULATE_PREPARES,false);
    $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    $sql = "INSERT INTO [gpsを入れたいテーブル名] (lat,lng) VALUES (?, ?)";
    $stmt = $dbh->prepare($sql);
    
    $stmt->bindValue(1, $lat, PDO::PARAM_STR);
    $stmt->bindValue(2, $lng, PDO::PARAM_INT);
    
    $stmt->execute();
    $dbh = null;
    echo "GPSの登録が完了しました。";
} catch (\Exception $e) {
    echo "エラー発生： " . htmlspecialchars($e->getMessage(), ENT_QUOTES, 'UTF-8') . "<br>";
    die();
}

 ?>