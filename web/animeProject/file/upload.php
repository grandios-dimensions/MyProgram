<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>ファイルをアップロード</title>
</head>
<body>
    <?php
    $tempfile = $_FILES['fname']['tmp_name'];
    $filename = './uploaded/' . $_FILES['fname']['name'];
    
    if (is_uploaded_file($tempfile)) {
        if ( move_uploaded_file($tempfile , $filename )) {
        echo $filename . "をアップロードしました。";
        } else {
            echo "ファイルをアップロードできません。";
        }
    } else {
        echo "ファイルが選択されていません。";
    } 
    ?>

    <p>
        <a href="../home.html">
            <button type="button">Homeに戻る</button>
        </a>
    </p>

</body>
</html>