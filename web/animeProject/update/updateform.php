<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>更新データの入力</title>
</head>
<body>

<?php
require_once("connect.php");
$pdo = db_connect();

$animeID = htmlspecialchars($_POST['animeID'], ENT_QUOTES, 'UTF-8');
$_SESSION['animeID'] = $animeID;
try{
    $sql ="SELECT * FROM newanime WHERE animeID =:animeID";
    $stmh = $pdo->prepare($sql);
    $stmh->bindValue(':animeID', $animeID, PDO::PARAM_INT);
    $stmh->execute();
    $count = $stmh->rowCount();
    
 } catch(PDOException $Exception){
    print "エラー:" . $Exception->getMessage();
}

if($count < 1){
    print "更新データがありません";
}else{
    $row = $stmh->fetch(PDO::FETCH_ASSOC);
?>
<form name ="form1" method="post" action="update.php">
        アニメ名:<?=htmlspecialchars($row['title'])?><br>
        番号 : <input type="number" name="animeID" value="<?=htmlspecialchars($row['animeID'])?>"><br>
        アイコン:<input type="text" name="aicon" required><br>
        OP:<input type="text" name="OP" required><br>
        Ed:<input type="text" name="ED" required><br>
        primeのリンク<input type="text" name="viewLink" required><br>
        <input type="submit" value="更新">
</form>

<?php
}
?>
    <p>
        <a href="./updateform.html">
            <button type="button">戻る</button>
        </a>
    </p>               

</body>
</html>