#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct bank{
	int all[MAX];
	int max[MAX];
	int need[MAX];
	int flag;
};

int main()
{
	int n,r,pno;
  printf("Enter the number of process\n");
  scanf("%d",&n);
  struct bank f[n];
  printf("Entre the number of resources\n");
  scanf("%d",&r);
  int avail[]={3,3,2};
 for(int i=0;i<n;i++)
 {
	 int data=0;
	 printf("Enter the alloacated resources to process[%d]",i);
	 for(int j=0;j<r;j++){
		scanf("%d",&data);
		f[i].all[j]=data;
		f[i].flag=0;
	 }
	 printf("Enter the max resources to process[%d]",i);
	 for(int j=0;j<r;j++){
	scanf("%d",&data);
	f[i].max[j]=data;
	 }
    }
 for(int i=0;i<n;i++)
 {
	 for(int j=0;j<r;j++){
	 f[i].need[j]=f[i].max[j]-f[i].all[j];
	 }
 }
 for(int i=0;i<n;i++)                                                                                                                                                    {                                                                                                                                                                               for(int j=0;j<r;j++){                                                                                                                                                   printf("%d ",f[i].need[j]); }
	 printf("\n");
	  }

 /*
 printf("Enter the Numners of available resourcess\n");
 for(int i=0;i<r;i++)
 {
	 int data=0;
scanf("%d",&avail[i]);
 }*/
 printf("Printing the allocation memeory\n");
 for(int i=0;i<n;i++)
 {
	 for(int j=0;j<r;j++)
	 printf("%d ",f[i].all[j]);
	 printf("\n");
 }
 printf("Enter the new request details\nenter the process id\n");
 scanf("%d",&pno);
/* for(int i=0;i<r;i++)
 {
	 int new;
	 scanf("%d",&new);
	 f[pno].all[i]+=new;
	 avail[i]-=new;
 }
*/
 int count=0,g=0,b=0;
 while(count!=n)
 {
	 printf("when counr is %d  \n",count);
	 g=0;
	 for(int i=0;i<n;i++){
		 if(f[i].flag==0){
		 b=0;
		 for(int j=0;j<r;j++){
                     if(f[i].need[j]<=avail[j])
			     b=b+1;
		     else
			     b=b-1;
		 }
		 
		 if(b==r){
			 printf("process[%d] get executed now\n",i);
			 for(int k=0;k<r;k++)
				 avail[k]+=f[i].all[k];

			 printf("(");
                         for(int l=0;l<r;l++)
			 printf( "%d ",avail[l]);
			 
			printf(")\n");

		         count++;
			 g=1;
			 f[i].flag=1;
		 }
	    }
	 }
	 if(g==0){
	        printf("Process are not in the safe states\n");
		break;
	 }
} 


	return 0;
}
