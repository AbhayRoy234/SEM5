#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int main()
{
	int pn,ps,rempages,fn,pgn,off,ms;
	int choice=0,s[10];
	printf("Enter the memeory size\n");
	scanf("%d",&ms);
	printf("Enter the each page size\n");
	scanf("%d",&ps);
	rempages=ms/ps;
        printf("Enter the number of the process\n");
	scanf("%d",&pn);
	int pg_table[pn][rempages];
	for(int i=0;i<pn;i++)
	{
		printf("Enter the number of the pages yoy want for process %d\n",i);
		scanf("%d",&s[i]);
		if(s[i]>=rempages)
		{
			printf("Memory  have no enough spaces\n");
			break;
		}
		else{
			printf("Enter the page table of the process %d",i);
			for(int j=0;j<s[i];j++)
			{
				scanf("%d",&pg_table[i][j]);
			}
			rempages-=s[i];
		}
	}
for(int i=0;i<pn;i++){
	for(int j=0;j<s[i];j++)
		printf("%d ",pg_table[i][j]);
	printf("\n");
}
int p,pg,of;

	printf("Enter the process no ,page no,offset value to\n find the physical addres of the \n");
	scanf("%d%d%d",&p,&pg,&of);
	if(p>=pn || pg>=(ms/ps) || of>=ps)
	{
		printf("Invalid input\n");
	}
	else{
		printf("%d\n",((pg_table[p][pg]*ps)+of));
	}

	return 0;
}
