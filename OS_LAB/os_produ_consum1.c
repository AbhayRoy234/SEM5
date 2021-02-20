#include<stdio.h>
//#include<stdlib.h>
//#include<sys/wait.h>
int mutex=1,full=0,empty=3,x=0;

int wait(int n){
     return (--n);
}

int signal(int n)
{
    return (++n);
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	++x;
	printf("\nproducer produces the iten no %d\n",x);
	mutex=signal(mutex);
}

void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nconsumer consumes the iten no %d\n",x--);
	mutex=signal(mutex);
}
int main()
{

	int n;
	while(1){
	printf("Enter your choice\n1.producer\n2.Consumer\n3.Exit\n");
        scanf("%d",&n);
	switch(n)
	{
		case(1):
			if(mutex==1 && empty!=0)
				producer();
			else
			
				printf("Buffer is full\n");
				break;
			
		case(2):
		if(mutex==1 && full!=0)
			consumer();
		else
			printf("Ther is no item\n");
			break;
		
		case(3):
		return 0;
	}
    }
return 0;
}
