#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* linking;	
}Node;

Node* Newnode(void);
void printList(Node* ); 
int main(){
	
	Node *List_head, *temp;
	int i,N;
	//initiate
	//List_head=temp=NULL;
	//scanf N;
	printf("How many data do you save? Ans: ");
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		if(i==1){//First data
			List_head= Newnode();
			temp=List_head;
			printf("Input 1st data= ");
			scanf("%d",&List_head->data);
		}
		else {//declare new data
			temp->linking=Newnode();
			printf("Input %d th data= ",i);
			scanf("%d",&temp->linking->data);
			temp=temp->linking;
		}	
	}
	temp->linking=NULL;
	//output data
	printList(List_head);
	//Delete Data
	while(List_head!=NULL){
		Node* t;
		t=List_head;
		List_head=List_head->linking;
		free(t);
	}
	printf("Delete Data......\n");
	//inspect
	printList(List_head);
	return 0;
}

Node* Newnode(void){
	Node* pt;
	pt=(Node*) malloc(sizeof(Node));
	if(pt==NULL)
		printf("Memeory is not enough!!");
	return pt;
	
}

void printList(Node* head){
	
	Node* tmp;
	int i=1;
	tmp=head;
	if(tmp==NULL)
		printf("There is no data now!!");
	else
		while(tmp!=NULL){
			printf("Data %d :%d\n",i,tmp->data);
			tmp=tmp->linking;
			i++;
		}
}
