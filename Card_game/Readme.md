# Card game--Big two
This program is to implement "Big two".

For how to deal card is to take following linking as reference:

- [Poker] 撲克牌遊戲設計介紹 (Translation:Poker game design introduction)
http://edisonx.pixnet.net/blog/post/54675090-%5Bpoker%5D-%E6%92%B2%E5%85%8B%E7%89%8C%E9%81%8A%E6%88%B2%E8%A8%AD%E8%A8%88%E4%BB%8B%E7%B4%B9 

- [RAND] 亂數進階議題 (Translation: Random number advance issue)
http://edisonx.pixnet.net/blog/post/72607067

And the conditional formula, I think:
For player01's cards in sequence: single, one pair, three cards, straight four cards (irons), do the sorting check (the full house and the flush and one dragon have not been completed yet)

Before distributing cards, for the probability of playing cards, follow the method suggested by the web moderator to spread the probability a little.
The cards of the four people are in the form of single cards.

However, after several revisions, column A has not been changed. So I still use 1~13 to represent A~JQK.
I have a struct
Come to count the cards and count the suits.

# Founctions

1. Deal card
void shuttle(int *array, int Size)→swap card
void display_poker(int *poker, int Size)→display card

2.  only for one user, to Calculate one user's card 
Player combination(int *poker)

3. Different card pair
void show_way(Player play)
void onepair(Player play,int i)
void three_cards(Player play,int i)
void four_cards(Player play,int i)
void straight(Player play,int i)
