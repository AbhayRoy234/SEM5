#include<stdio.h>
#include<omp.h>
int main()
{
#pragma omp parallel
	{
		printf("Hello Word id Printed By %d Thred\n",omp_get_thread_num());
	}
	return 0;
}
