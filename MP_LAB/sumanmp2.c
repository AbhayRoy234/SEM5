
#include<stdio.h>
#include<omp.h>

int fib(int n)
{
        if (n<2) return n;
        else return fib(n-1) + fib(n-2);

}
int main()
{
        int fib_no[100],i,j,n;
        printf("Enter the upper limit");
        scanf("%d",&n);
        #pragma omp parallel num_threads(2)
        {
                #pragma omp critical
                if (omp_get_thread_num() == 0)
                {
                        printf("There are %d threads",omp_get_num_threads());
                        printf("Thread %d is used for counting",omp_get_thread_num());
                        for(i=0;i<n;i++)
                        {
                                fib_no[i] = fib(i);
                        }
                }
                else
                {
                        printf("Thread %d is used for printing numbers",omp_get_thread_num());
                        for(j=0;j<n;j++)
                        {
                                printf("%d\t",fib_no[j]);
                        }
                }
        }
        return 0;
}