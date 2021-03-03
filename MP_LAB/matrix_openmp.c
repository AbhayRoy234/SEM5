#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define M 3
#define N 3
#define P 3


int main()
{
	int tid,i,j,k;

	double A[N][P],B[P][M],C[N][M];
	
#pragma omp parallel shared(A,B,C) private(tid,i,j,k)
	{
		tid=omp_get_thread_num();
#pragma omp for
	for(i=0;i<N;i++)
	for(j=0;j<P;j++)
	A[i][j]=i+j;

#pragma omp for 
	for(i=0;i<P;i++)
	for(j=0;j<M;j++)
	B[i][j]=i*j;

#pragma omp parallel
	 for(i=0;i<N;i++)                                                                   for(j=0;j<M;j++)                                                                   C[i][j]=0;


printf("thread %d started multipliying\n",tid);
#pragma omp for
for(i=0;i<N;i++){
printf("Thread = %d did row %d\n",tid,i);
for(j=0;j<M;j++)
for(k=0;k<P;k++)
C[i][j]+=A[i][k]*B[k][j];
}

}

for(i=0;i<N;i++){                                                                   for(j=0;j<M;j++){                                                                   printf("%6.2f",C[i][j]);
}
printf("\n");
}


return 0;
}
