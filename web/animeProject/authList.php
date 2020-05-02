<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>アニメを表示</title>
</head>
<body>

    <?php 
    $user = [phpmyadminのユーザ名];
    $pass = [phpmyadminのパスワード];

    try {
        $pdo = new PDO('mysql:host=localhost;dbname=anime;charset=utf8', $user, $pass);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    }catch(PDOException $Exception){
        die('接続エラー：' .$Exception->getMessage());
    }

    try{
        $sql = "SELECT * FROM newanime ORDER BY title ASC";
        $stmh = $pdo->query($sql);
        $result = $stmh->fetchAll(PDO::FETCH_ASSOC);
    }catch(PDOException $Exception){
        die('接続エラー：' .$Exception->getMessage());
    }
    ?>

    <table border="1" cellspacing="0"><tbody>
        <tr><th>アイコン</th><th width="200">アニメ名</th><th>OP</th><th>ED</th><th>viewLink</th><th>twitterLink</th><th>pixivLink</th><th>id</th></tr>
    <?php
        foreach ($result as $row){
    ?>
        <tr>
            <td><p><img src="<?= htmlspecialchars($row['aicon'], ENT_QUOTES, 'UTF-8') ?>" width="50" height="50" alt="A"></p></td>
            <td width="200"><?= htmlspecialchars($row['title'], ENT_QUOTES, 'UTF-8') ?></td>
            <td><p><a href="<?= htmlspecialchars($row['OP'], ENT_QUOTES, 'UTF-8') ?>">OP</a></p></td>
            <td><p><a href="<?= htmlspecialchars($row['ED'], ENT_QUOTES, 'UTF-8') ?>">ED</a></p></td>
            <td><p><a href="<?= htmlspecialchars($row['viewLink'], ENT_QUOTES, 'UTF-8') ?>">今すぐ観る</a></p></td>
            <td><p><a href="<?= htmlspecialchars($row['twitterLink'], ENT_QUOTES, 'UTF-8') ?>">twitter</a></p></td>
            <td><p><a href="<?= htmlspecialchars($row['pixivLink'], ENT_QUOTES, 'UTF-8') ?>">pixiv</a></p></td>
            <td><?= htmlspecialchars($row['animeID'], ENT_QUOTES, 'UTF-8') ?></td>
        </tr>
    <?php
        }
        $pdo = null;
    ?>
    </tbody></table>

    <!--ここでmp3を指定するとbgmとして流せる

    <audio src="[曲名].mp3" autoplay loop></audio>

    -->

    <p>
        <a href="./home.html">
            <button type="button">Homeに戻る</button>
        </a>
    </p>
</body>
</html>