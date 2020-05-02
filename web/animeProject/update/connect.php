<?php 
function db_connect(){
    $user = [phpmyadminのユーザ名];
    $pass = [phpmyadminのパスワード];

    try {
        $pdo = new PDO('mysql:host=localhost;dbname=anime;charset=utf8', $user, $pass);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    }catch(PDOException $Exception){
        die('接続エラー：' .$Exception->getMessage());
    }
    return $pdo;
}
?>