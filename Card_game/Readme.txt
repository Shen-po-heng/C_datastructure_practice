�Z�šG�q���TB 104501019 �H�f��

�o�����j�ѤG�{�� 
��󬣵P�A�ڰѦҳo�Ӻ���
[Poker] ���J�P�C���]�p����
http://edisonx.pixnet.net/blog/post/54675090-%5Bpoker%5D-%E6%92%B2%E5%85%8B%E7%89%8C%E9%81%8A%E6%88%B2%E8%A8%AD%E8%A8%88%E4%BB%8B%E7%B4%B9 
[RAND] �üƶi��ĳ�D
http://edisonx.pixnet.net/blog/post/72607067
�ӱ��󦡡A�ڬO�o��Q�G
���player01���P�̧ǹ�: ��� �@�� �T�i ���l �|�i(�K��) ���Ƨ��ˬd(�|������Full House�M�P�ᶶ�M�@���s)

�e�����P�A���X�P���v�A���Ӻ������D��ĳ���覡�����v�����@�I�C
�|�ӤH���P�N�H�@��single���X�P�Φ��F�C

�ӫ᭱�睊�h���A�٥��ﱼ1�CA�C�ҥH�ڥثe�٬O��1~13���A~JQK�C
�ڦ��O�@��struct
�ӹ�P���p�ơA�٦��p���C

�禡�ѻ�
1.�o�P�@��
void shuttle(int *array, int Size)���洫�P��
void display_poker(int *poker, int Size)����ܵP��

2.�o��u�缾�a�@ �ϥΡA�i�p�⪱�a�@ ���A�U�Ʀr�P���i�ƩM���O����
Player combination(int *poker)

3.
void show_way(Player play)���i�ܩҦ��P���A�N�U�z���P���禡�c�J������
void onepair(Player play,int i)
void three_cards(Player play,int i)
void four_cards(Player play,int i)
void straight(Player play,int i)

4.�D�禡
int main(){	
    Player player01;
    int i, poker[N];
    for(i=0; i!=N; ++i) poker[i] = i;
    shuttle(poker, N);
    printf("�o�P:\n");
    display_poker(poker, N);

    printf("Player 1���P�դ��R:\n");
    player01=combination(poker);
    show_way(player01);
	return 0;
}
(�Y�٦��ק�|�A�ǧ�U��~�����[�\)