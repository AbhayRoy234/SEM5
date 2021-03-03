#include<stdio.h>
#include<omp.h>
int fib(int n)
{
	if (n<2) return n;
	else return fib(n-1)+fib(n-2);
}

int main()
{
	int i,n,fib_no[100];
	printf("Eter the max limit\n");
	scanf("%d",&n);
#pragma omp parallel num_threads(2)
	{
	#pragma omp critical
	       if(omp_get_thread_num()==0)
	       {
		       printf("Thread number %d udes for counting\n",omp_get_thread_num());
		       for(i=0;i<n;i++)
			fib_no[i]=fib(i);
	       }

           else{
		   printf("Thread %d is use for printing\n",omp_get_thread_num());
		   for(i=0;i<n;i++)
		   {
			   printf("%d\n",fib_no[i]);
		   }
	   }		   
	}

	return 0;
}
