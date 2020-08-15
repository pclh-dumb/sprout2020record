把bmp檔讀進來並處理好的程式是由資訊之芽團隊所製作，我的任務是把一個bmp檔轉成  
ASCII ART(每一個點由符號組成)，分別要轉換成輪廓、灰階，以及彩色(256color)的。  
資訊之芽網址:https://tw-csie-sprout.github.io/c2020/#!project2.md
(我在寫的時候是用linux測試，windows跑起來好像會怪怪的)  


在bg_color.cpp中，我把RGB轉換成256色的方法是這樣的:
1.先把顏色分成6個區段
2.用迴圈的方式找到作接近它的256色代碼
接下來就印出圖案就好了

在edge_detect.cpp中，我使用模糊化的濾鏡來讀圖片，而閥值的部分，因為我挑了一個顏色
較淡的圖片，所以閥值是用小於來判別。

在grayscale.cpp中，我先把RGB三個值平方、相加、除以三，然後再開根號(投影片的方法)，
得到最終的數值後，我把顏色分成25個等級，然後再對照到231~255的色碼。

在bonus.cpp中，我做了一個小小的動畫，利用清除螢幕螢幕及暫停的功能來讓圖片動起來，
但其時效果不是到非常好，會有停頓的現像。我也曾試著想把小精靈的食物也放進動畫中，
但後來實在無法解決，就放棄了。另外，每當小精靈回到一開始的地方時，它身上的符號就會
在ASCII code上往後推一個，所以每一輪的符號都會不一樣。

圖片來源:
30pacmanClose.bmp pac.bmp : https://zh.wikipedia.org/wiki/%E5%90%83%E8%B1%86%E4%BA%BA#/media/File:Pac-Man.svg
celtics450.bmp : https://a.espncdn.com/i/teamlogos/nba/500-dark/bos.png  
git1.bmp : https://img.technews.tw/wp-content/uploads/2019/11/12134205/%E6%9C%AA%E5%91%BD%E5%90%8D.jpg  
gold.bmp : https://www.clipartmax.com/middle/m2i8d3m2G6A0K9H7_the-golden-snitch-back-cartoon-snitch-harry-potter/
