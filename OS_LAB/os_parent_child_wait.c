#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t id1=fork();
	pid_t id2=fork();
	if(id1>0 && id2>0){
		wait(NULL);
		wait(NULL);
		printf("Parent terminated\n");
	}
	else if(id1==0 && id2>0)
	{
		sleep(2);
		wait(NULL);
		printf("1 st child terminated\n");

	}
	else if(id1>0 && id2==0){	  
		sleep(1);
//		wait(NULL);
		printf("2 st child terminated\n");

	}
	else{
		printf("Grand childeren terminated\n");
	}

	return 0;

}
