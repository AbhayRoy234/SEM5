#include<stdio.h>
#include<omp.h>
int main()
{
int n=4;
omp_set_num_threads(n);
#pragma omp parallel 
{
	int id=omp_get_thread_num();
	printf("Hello World is Printed By Thred No. %d\n",id);

}
printf("Total No. Of Threads are %d\n",n);
return 0;
}

