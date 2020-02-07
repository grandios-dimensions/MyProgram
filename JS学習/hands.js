var hand;

function janken(hand){

  machineHand = Math.floor(Math.random()*3);

  document.write('<h2>ポン!</h2>');

  if(machineHand == 0){
    document.write('<img src="./image/gu.jpg" alt="画像の解説文" width="200" height="200"/>');
  }else if(machineHand == 1){
    document.write('<img src="./image/tyoki.jpg" alt="画像の解説文" width="200" height="200"/>');
  }else if(machineHand == 2){
    document.write('<img src="./image/pa.jpg" alt="画像の解説文" width="200" height="200"/>');
  }

  document.write("<br>");
  var judge;

  if( (hand-machineHand+3) % 3 == 0 ){
    document.write('<h2>両者の引き分け</h2>');
  }else if( (hand-machineHand+3) % 3 ==  1){
    document.write('<h2>あなたの負け</h2>');
  }else if( (hand-machineHand+3) % 3 == 2 ){
    document.write('<h2>あなたの勝ち</h2>');
  }              

}


