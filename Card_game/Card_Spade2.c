#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 52
#define SWAP(a, b){int t; t=a; a=b; b=t;}


#define BUF_SIZE 3
const char flower[4] = {'C','D','H','S'}; // 4個花色
const char number[13][BUF_SIZE] = {
    "A", "2", "3", "4", "5", "6",
    "7", "8", "9", "10", "J", "Q", "K"};
	
	typedef struct cards_information_player{
		int card_count[13];
		int card_flower[13][4];
	}Player;

// ====================================
// shuttle
void shuttle(int *array, int Size){
    int i, pos;
    srand((unsigned)time(NULL));
    rand(); // 先抽掉一個亂數

    for(i=0; i!=Size; ++i){
       // 取出第 pos 張牌
       pos = (int) (N*(double)rand()/(RAND_MAX+1.0)); // better
       // 將第 i 張牌與第 pos 張牌交換
       SWAP(array[i], array[pos]); 
    }
}

// ====================================
// display
void display_poker(int *poker, int Size){
    int i;
	int count=1;
    
    for(i=0; i!=Size; ++i) {
       // 顯示花色, flower_index = poker[i] % 4
       if(i%13==0)
       	printf("	Player %d:",count);
	   putchar(flower[ poker[i] % 4 ]); 
       // 顯示點數, number_index = poker[i] / 4
       printf("%s \t", number[ poker[i] >> 2 ]); 
       if(i%13==12){
     	putchar('\n');
       	count++;
       }
	}
}

Player combination(int *poker){

	int i;
	Player player;	

	for(i=0;i<13;i++){
		player.card_count[i]=0;
		player.card_flower[i][0]=0;
		player.card_flower[i][1]=0;
		player.card_flower[i][2]=0;
		player.card_flower[i][3]=0;
	}
	for(i=0;i<13;i++){
		poker[i]>>2;
		player.card_count[ poker[i]>>2 ]++;
		player.card_flower[ poker[i]>>2 ][poker[i] % 4 ]=1;
		
	}
	
	for(i=0;i<13;i++){
	
		printf("%d : %d\n",i+1,player.card_count[i]);
		printf("club: %d\t",player.card_flower[i][0]);
		printf("diamond: %d\t",player.card_flower[i][1]);
		printf("heart: %d\t",player.card_flower[i][2]);
		printf("spade: %d\n",player.card_flower[i][3]);}
		return player;
	}
	
	
void onepair(Player play,int i){
	if(play.card_flower[i][0]==1 && play.card_flower[i][1]==1)
			printf("[C%d & D%d]",i+1,i+1);
	if(play.card_flower[i][0]==1 && play.card_flower[i][2]==1)
			printf("[C%d & H%d]",i+1,i+1);
	if(play.card_flower[i][0]==1 && play.card_flower[i][3]==1)
			printf("[C%d & S%d]",i+1,i+1);		
	if(play.card_flower[i][1]==1 && play.card_flower[i][2]==1)
			printf("[D%d & H%d]",i+1,i+1);		
	if(play.card_flower[i][1]==1 && play.card_flower[i][3]==1)
			printf("[D%d & S%d]",i+1,i+1);		
	if(play.card_flower[i][2]==1 && play.card_flower[i][3]==1)
			printf("[H%d & S%d]",i+1,i+1);
}
void three_cards(Player play,int i){
	if(play.card_flower[i][0]==1 && play.card_flower[i][1]==1 && play.card_flower[i][2]==1)
			printf("[C%d & D%d & H%d]",i+1,i+1,i+1);
	if(play.card_flower[i][0]==1 && play.card_flower[i][1]==1 && play.card_flower[i][3]==1)
			printf("[C%d & D%d & S%d]",i+1,i+1,i+1);
	if(play.card_flower[i][1]==1 && play.card_flower[i][2]==1 && play.card_flower[i][3]==1)
			printf("[D%d & H%d & S%d]",i+1,i+1,i+1);
	if(play.card_flower[i][0]==1 && play.card_flower[i][2]==1 && play.card_flower[i][3]==1)
			printf("[C%d & H%d & S%d]",i+1,i+1,i+1);
}
void four_cards(Player play,int i){
	if(play.card_flower[i][0]==1 && play.card_flower[i][1]==1 )
		if(play.card_flower[i][2]==1 && play.card_flower[i][3]==1 )
			printf("[C%d & D%d & H%d & S%d]",i+1,i+1,i+1,i+1);
}

void straight(Player play,int i){
	int j;
	for(j=i;j<i+5;j++){
		
		if(j==i)
			printf("[");
		else if(j<i+5)
			printf("&");
			
		if(j<=13){
		if(play.card_flower[j][0]==1){
			printf("C%d",j+1);
		}
		else if(play.card_flower[j][1]==1){
			printf("D%d",j+1);
		}
		else if(play.card_flower[j][2]==1){
			printf("H%d",j+1);
		}
		else if(play.card_flower[j][3]==1){
			printf("S%d",j+1);
		}
		}
		else{
			if(play.card_flower[j%13][0]==1){
			printf("C%d",j+1);
		}
		else if(play.card_flower[j%13][1]==1){
			printf("D%d",j+1);
		}
		else if(play.card_flower[j%13][2]==1){
			printf("H%d",j+1);
		}
		else if(play.card_flower[j%13][3]==1){
			printf("S%d",j+1);
		}
		}
		if(j==(i+4))
			printf("]");
	}
	
}
void show_way(Player play){
	int i;
	printf("Single:\t(如上述的player1)\n");
	printf("1 pair:\t");
	for(i=0;i<13;i++)//1pair
		if(play.card_count[i]==2 ||play.card_count[i]==3||play.card_count[i]==4){
			switch (i){
				case 0:
					onepair(play,i);
				break;
				case 1:
					onepair(play,i);
				break;
				case 2:
					onepair(play,i);
				break;
				case 3:
					onepair(play,i);
				break;
				case 4:
					onepair(play,i);
				break;
				case 5:
					onepair(play,i);
				break;
				case 6:
					onepair(play,i);
				break;
				case 7:
					onepair(play,i);
				break;
				case 8:
					onepair(play,i);
				break;
				case 9:
					onepair(play,i);
				break;
				case 10:
					onepair(play,i);
				break;
				case 11:
					onepair(play,i);
				break;	
				case 12:
					onepair(play,i);
				break;	
		}
	}
		
	printf("\n3 card:\t");	
		for(i=0;i<13;i++)//3cards 
		if(play.card_count[i]==3){
			switch (i){
				case 0:
					three_cards(play,i);
				break;
				case 1:
					three_cards(play,i);
				break;
				case 2:
					three_cards(play,i);
				break;
				case 3:
					three_cards(play,i);
				break;
				case 4:
					three_cards(play,i);
				break;
				case 5:
					three_cards(play,i);
				break;
				case 6:
					three_cards(play,i);
				break;
				case 7:
					three_cards(play,i);
				break;
				case 8:
					three_cards(play,i);
				break;
				case 9:
					three_cards(play,i);
				break;
				case 10:
					three_cards(play,i);
				break;
				case 11:
					three_cards(play,i);
				break;	
				case 12:
					three_cards(play,i);
				break;	
			}
		}
		printf("\n4 cards:");	
		for(i=0;i<13;i++)//4cards 
		if(play.card_count[i]==4){
			switch (i){
				case 0:
					four_cards(play,i);
				break;
				case 1:
					four_cards(play,i);
				break;
				case 2:
					four_cards(play,i);
				break;
				case 3:
					four_cards(play,i);
				break;
				case 4:
					four_cards(play,i);
				break;
				case 5:
					four_cards(play,i);
				break;
				case 6:
					four_cards(play,i);
				break;
				case 7:
					four_cards(play,i);
				break;
				case 8:
					four_cards(play,i);
				break;
				case 9:
					four_cards(play,i);
				break;
				case 10:
					four_cards(play,i);
				break;
				case 11:
					four_cards(play,i);
				break;	
				case 12:
					four_cards(play,i);
				break;	
			}
		}

	printf("\nstraight:");//straight 
	int j,count;
		for(i=0;i<12;i++){
			if(i<=9){
				count=0;
			for(j=i;j<i+5;j++){
				if(play.card_count[j]>0){
					count++;
					if(count==5){					
						straight(play,i);
					}
				}
			}}
			else{
					count=0;
				for(j=i;j<i+5;j++){
					if(j<=13)
					if(play.card_count[j]>0){
						count++;
						if(count==5)
							straight(play,i);
					}
					else{
						if(play.card_count[j%13]>0){
							count++;
						if(count==5)
							straight(play,i);
					}
					}
				}
			}
		}

		
}	


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
    system("pause");
	return 0;
}
