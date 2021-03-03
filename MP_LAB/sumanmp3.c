#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3               /* number of rows in matrix A */
#define P 3                /* number of columns in matrix A */
#define M 3                  /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
int	tid, i, j, k;
double	a[N][P],           /* matrix A to be multiplied */
	b[P][M],           /* matrix B to be multiplied */
	c[N][M];           /* result matrix C */



#pragma omp parallel shared(a,b,c) private(tid,i,j,k)
  {
  tid = omp_get_thread_num();

  #pragma omp for 
  for (i=0; i<N; i++)
    for (j=0; j<P; j++)
      a[i][j]= i+j;
  #pragma omp for 
  for (i=0; i<P; i++)
    for (j=0; j<M; j++)
      b[i][j]= i*j;
  #pragma omp for 
  for (i=0; i<N; i++)
    for (j=0; j<M; j++)
      c[i][j]= 0;

  
  printf("Thread %d starting matrix multiply...\n",tid);
  #pragma omp for
  for (i=0; i<N; i++)    
    {
    printf("Thread=%d did row=%d\n",tid,i);
    for(j=0; j<M; j++)       
      for (k=0; k<P; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }  
printf("Result Matrix:\n");
for (i=0; i<N; i++)
  {
  for (j=0; j<P; j++) 
    printf("%6.2f   ", c[i][j]);
  printf("\n"); 
  }

printf ("Done.\n");

}