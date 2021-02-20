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
	int arr_frame[f];
	for(int i=0;i<f;i++)
		arr_frame[i]=-1;
	int count=0,flags=0,pf=0,j;
	for(int i=0;i<n;i++)
	{
		for(j=0;j<f;j++){
		if(arr_frame[j]==arr[i])
		{
			break;
		}
		}
		if(j==f)
		{
			
			arr_frame[count++]=arr[i];
			pf++;
		}
		printf("%d\t%d\t%d\t\t",arr_frame[0],arr_frame[1],arr_frame[2]);
		if(j==f)
			printf("page fault no %d \n",pf);
		printf("\n");
		if(count==f)
			count=0;

	}
	printf("here we get total %d page faults\n",pf);
}
