<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>アニメを登録</title>
</head>
<body>
<?php 
$user = [phpmyadminのユーザ名];
$pass = [phpmyadminのパスワード];

$aicon = htmlspecialchars($_POST['aicon'], ENT_QUOTES, 'UTF-8');
$title = htmlspecialchars($_POST['title'], ENT_QUOTES, 'UTF-8');
$OP = htmlspecialchars($_POST['OP'], ENT_QUOTES, 'UTF-8');
$ED = htmlspecialchars($_POST['ED'], ENT_QUOTES, 'UTF-8');
$viewLink = htmlspecialchars($_POST['viewLink'], ENT_QUOTES, 'UTF-8');
$twitterLink = "https://twitter.com/hashtag/".htmlspecialchars($_POST['title'], ENT_QUOTES, 'UTF-8');
$pixivLink = "https://www.pixiv.net/tags/".htmlspecialchars($_POST['title'], ENT_QUOTES, 'UTF-8');

try {
    $pdo = new PDO('mysql:host=localhost;dbname=anime;charset=utf8', $user, $pass);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES,false);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    $sql = "INSERT INTO newanime (aicon, title, OP, ED, viewLink, twitterLink, pixivLink) VALUES (?, ?, ?, ?, ?, ?, ?)";
    $stmt = $pdo->prepare($sql);
    
    $stmt->bindValue(1, htmlspecialchars($aicon, ENT_QUOTES, 'UTF-8'), PDO::PARAM_STR);
    $stmt->bindValue(2, htmlspecialchars($title, ENT_QUOTES, 'UTF-8'), PDO::PARAM_INT);
    $stmt->bindValue(3, htmlspecialchars($OP, ENT_QUOTES, 'UTF-8'), PDO::PARAM_INT);
    $stmt->bindValue(4, htmlspecialchars($ED, ENT_QUOTES, 'UTF-8'), PDO::PARAM_INT);
    $stmt->bindValue(5, htmlspecialchars($viewLink, ENT_QUOTES, 'UTF-8'), PDO::PARAM_INT);
    $stmt->bindValue(6, htmlspecialchars($twitterLink, ENT_QUOTES, 'UTF-8'), PDO::PARAM_INT);
    $stmt->bindValue(7, htmlspecialchars($pixivLink, ENT_QUOTES, 'UTF-8'), PDO::PARAM_INT);
    
    $stmt->execute();
    $pdo = null;
    echo "アニメの登録が完了しました。";
} catch (\Exception $e) {
    echo "エラー発生： " . htmlspecialchars($e->getMessage(), ENT_QUOTES, 'UTF-8') . "<br>";
    die();
}

?>

<p>
        <a href="../home.html">
            <button type="button">Homeに戻る</button>
        </a>
</p>
</body>
</html>