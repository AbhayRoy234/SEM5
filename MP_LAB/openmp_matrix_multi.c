#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define N 3
#define M 3
#define P 3

int main()
{
	int tid,i,j,k;
	double a[N][P],b[P][M],c[N][M];

#pragma omp parallel shared(a,b,c) private(tid,i,j,k)
	{
		tid=omp_get_thread_num();
#pragma omp for
		for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			a[i][j]=i+j;
		}
		}
#pragma omp for
for(i=0;i<P;i++)
{
for(j=0;j<M;j++)
{
	b[i][j]=i*j;
}
}

#pragma omp for
for(i=0;i<N;i++)
for(j=0;j<M;j++)
c[i][j]=0;

printf("Thred %d started multiplying\n",tid);
#pragma omp for
for(i=0;i<N;i++){
	printf("THREAD %d  is executed by %d ",tid,i);
	for(j=0;j<M;j++)
		for(k=0;k<P;k++)
			c[i][j]+=a[i][k]*b[k][j];
		
}
}
printf("this id the result of the multiplication of the mattrix\n");
for(i=0;i<N;i++){
for(j=0;j<M;j++){
printf("%6.2f  ",c[i][j]);
}
printf("\n");
}
	return 0;
}
