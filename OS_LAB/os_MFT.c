#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,ms,bs,total,pc,internla_frag=0,external_frag=0;
	printf("Enter the total memory available\n");
	scanf("%d",&ms);
	printf("Enter the block size \n");
	scanf("%d",&bs);
	printf("Enter the numberr of the process you want to allocate spacces\n");
	scanf("%d",&pc);
	int process_block[pc];
	total=ms;
	int block_no=ms/bs;
	external_frag=ms%bs;
	for(int i=0;i<pc;i++)
	{
		printf("Enter the page size for process %d  \n",i);
		scanf("%d",&process_block[i]);
	}
	int p=0;
	for(int i=0;i<n && p<block_no;i++)
	{
		if(bs>=process_block[i]){
			printf("Memroy Allocated to the\n process %d of size %d \nhaving internal fragmentation %d \n ",i,process_block[i],bs-process_block[i]);
			internla_frag+=bs-process_block[i];
			p++;
		}
		else{
			printf("we can't allocated spaces to\n process %d\n",i);
		}
	}
	printf("total internal frag %d\n",internla_frag);
	printf("total external  frag %d\n",external_frag);
	printf("total eused spaces %d\n",total-(external_frag+internla_frag));
return 0;
}
