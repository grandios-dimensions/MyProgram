<?php

  //ヘッダー情報の設定
  header("Content-Type: application/json; charset=utf-8");

  $data = array();

  // DB接続情報
  $user = "[phpmyadminのユーザー名]";
  $pass = "[phpmyadminのパスワード]";

  // DB接続情報設定・SQL準備・接続
  $dbh = new PDO('mysql:host=localhost;dbname=[gpsを取得するデータベース名];charset=utf8', $user, $pass);

  $sql = "select lat, lng from [gpsを取得するテーブル名]";
  $sth = $dbh -> prepare($sql);
  $sth -> execute();

  //データを取得する
  $data = $sth -> fetchAll(PDO::FETCH_ASSOC);

  //jsonオブジェクト化
  echo json_encode($data);
?>