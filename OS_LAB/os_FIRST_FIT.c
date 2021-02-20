#include <stdio.h>
#include<stdlib.h>

int main(void) {
	int file[] = {40,20,500,30,10};
	int partition[] = {60,20,50,10};
	int flag;
	int len_file=sizeof(file)/sizeof(file[0]);
	int len_partition = 4;
	
	for(int i=0; i<len_file; i++){
	    flag = 0;
	    for(int j=0; j<len_partition; j++){
	        if(file[i]<=partition[j]){
	            partition[j] -= file[i];
	            printf("file %d is allocted to partition %d and after fragmentation size available is %d\n", i+1,j+1,partition[j]);
	            flag = 1;
	            break;
	        }
	    }
	    if (flag==0){
	            printf("Couldn't alloct any partition for file %d\n",i+1);
	        }
	}
	
	return 0;
}
