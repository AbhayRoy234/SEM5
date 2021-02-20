#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("Enter the length of the string\n");
	scanf("%d",&n);
	int arr[n],f;
	printf("Enter the sequence of the string\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the number of the page frame     \n");
	scanf("%d",&f);
	int arr_frame[f],arr_count[f];
	for(int i=0;i<f;i++)
		arr_frame[i]=-1;
	int count=0,flag=0,pf=0,j;
	for(int i=0;i<n;i++)
	{
		flag=0;
	  for(j=0;j<f;j++)
	  {
		  if(arr_frame[j]==arr[i]){
			  flag=1;
			 arr_count[j]=count++;

		  }
	  }
	  if(flag==0)
	  {
		  if(i<f){
			arr_frame[i]=arr[i];
			arr_count[i]=count++;
		  }
		  else
		  {
			  int min=0;
			  for(int k=1;k<f;k++){
                              if(arr_count[min]>arr_count[k])
			      {
				      min=k;
			      }
			  }
			  arr_frame[min]=arr[i];
			  arr_count[min]=count++;

		  }
		  pf++;
		  printf("%d\t\t%d\t\t%d\t\t",arr_frame[0],arr_frame[1],arr_frame[2]); 
		  
		  printf("page falut no %d \n",pf);
	  }
	  if(flag==0)
	  printf("%d\t\t%d\t\t%d\t\t\n",arr_frame[0],arr_frame[1],arr_frame[2]);

	}
	printf("here we get total %d page faults\n",pf);
	return 0;
}
