#include<stdio.h>
#include<unistd.h>

int main()
{
int parent_id=getpid();
int child_id=getppid();
printf("Parent id is %d\n",parent_id);
printf("child id is %d\n",child_id);
	return 0;
}
