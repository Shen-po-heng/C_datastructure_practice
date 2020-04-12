#include <stdio.h> 
typedef struct friends{
	char birth[10];
	int sex;
	char name[10];	
}Friend;

int main(void){
	
	Friend f[3];
	Friend* p=f;
	int i;	
	for(i=0;i<3;i++,p++){
		printf("Input the No.%d friend:\n",i);
		
		printf("Name:"); 
		scanf("%s",p->name);
			
		printf("Sex:(boy=1,girl=2)");
		scanf("%d",&p->sex);
		
		printf("Birth Day:");
		scanf("%s",p->birth);
	}	
		int j;
	while(1){
		
		printf("Input:");
		scanf("%d",&j);
		printf("%s\n %d\n %s",f[j].name,f[j].sex,f[j].birth);
	}
}
