班級：電機三B 104501019 沈柏亨

這次的大老二程式 
對於派牌，我參考這個網站
[Poker] 撲克牌遊戲設計介紹
http://edisonx.pixnet.net/blog/post/54675090-%5Bpoker%5D-%E6%92%B2%E5%85%8B%E7%89%8C%E9%81%8A%E6%88%B2%E8%A8%AD%E8%A8%88%E4%BB%8B%E7%B4%B9 
[RAND] 亂數進階議題
http://edisonx.pixnet.net/blog/post/72607067
而條件式，我是這麼想：
對於player01的牌依序對: 單支 一對 三張 順子 四張(鐵支) 做排序檢查(尚未做完Full House和同花順和一條龍)

前面派牌，對於出牌機率，有照網頁版主建議的方式讓機率分散一點。
四個人的牌就以作為single的出牌形式了。

而後面改版多次，還未改掉1列A。所以我目前還是用1~13表示A~JQK。
我有令一個struct
來對牌做計數，還有計花色。

函式解說
1.發牌作用
void shuttle(int *array, int Size)→交換牌型
void display_poker(int *poker, int Size)→顯示牌型

2.這邊只對玩家一 使用，可計算玩家一 中，各數字牌的張數和花色是那些
Player combination(int *poker)

3.
void show_way(Player play)→展示所有牌型，將下述的牌型函式販入此式中
void onepair(Player play,int i)
void three_cards(Player play,int i)
void four_cards(Player play,int i)
void straight(Player play,int i)

4.主函式
int main(){	
    Player player01;
    int i, poker[N];
    for(i=0; i!=N; ++i) poker[i] = i;
    shuttle(poker, N);
    printf("發牌:\n");
    display_poker(poker, N);

    printf("Player 1的牌組分析:\n");
    player01=combination(poker);
    show_way(player01);
	return 0;
}
(若還有修改會再傳改助教~謝謝觀閱)