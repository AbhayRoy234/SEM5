#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ms,n,need,total;
	printf("Enter the size of the memory\n");
	scanf("%d",&ms);
	total=ms;
	printf("Enetr the number of process you want allocate spaces \n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enteer the memeory size for process %d\n",i);
		scanf("%d",&need);
		if(need<=ms){
			ms-=need;
			printf("pocess %d \nallocated %d spaces \nand left spaces is %d",i,need,ms);
		}
		else{
			printf("Not possible to allocate memeory\n");
			break;
		}
	}
	printf("Internal fregmmentation is %d\n",ms);
	printf("tital used memeory spaces are %d\n",total-ms);
	return 0;
}
