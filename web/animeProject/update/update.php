<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>データ更新結果</title>
</head>
<body>
<?php
require_once("connect.php");
$pdo = db_connect();

$animeID = htmlspecialchars($_POST['animeID'], ENT_QUOTES, 'UTF-8');
$_SESSION['animeID'] = $animeID;

try{
    $pdo->beginTransaction();
    $sql ="UPDATE newanime SET aicon =:aicon,OP =:OP,ED =:ED,viewLink =:viewLink where animeID=:animeID";
    $stmh = $pdo->prepare($sql);
    $stmh ->bindValue(':aicon',$_POST['aicon'], PDO::PARAM_STR);
    $stmh ->bindValue(':OP',$_POST['OP'], PDO::PARAM_STR);
    $stmh ->bindValue(':ED',$_POST['ED'], PDO::PARAM_STR);
    $stmh ->bindValue(':viewLink',$_POST['viewLink'], PDO::PARAM_STR);
    $stmh ->bindValue(':animeID',$animeID, PDO::PARAM_INT);
    $stmh->execute();
    $pdo->commit();
    print "データを". $stmh->rowCount()."件、更新しました。";
} catch(PDOException $Exception){
    print "エラー:" . $Exception->getMessage();
}

$_SESSION = array();

?>
    <p>
        <a href="../home.html">
            <button type="button">Homeに戻る</button>
        </a>
    </p>               
</body>
</html>