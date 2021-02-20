#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


void cal_turn_around_time(int process[],int burst_time[],int turn_time[],int n)
{
	int curr=0;
	for(int i=0;i<n;i++)
		{
			turn_time[process[i]]=burst_time[i]+curr;
			curr=turn_time[process[i]];
		}

}

void cal_waiting_time(int burst_time[],int waiting_time[],int turn_time[],int n){

	for(int i=0;i<n;i++)
	{
		waiting_time[i]=turn_time[i]-burst_time[i];
	}
}
void call_average(int burst_time[],int process[],int waiting_time[],int turn_time[],int n)
{
double sum=0,sum1=0;
cal_turn_around_time(process,burst_time,turn_time,n);
cal_waiting_time(burst_time,waiting_time,turn_time,n);
for(int i=0;i<n;i++)
{
sum+=waiting_time[i];
sum1+=turn_time[i];
}
printf("Average Waiting Time is %f\n",sum/n);
printf("Average turn around  Time is %f\n",sum1/n);

}

int main()
{
	int n=4;
int process[]={0,1,2,3};
int burst_time[]={3,6,7,8};
int turn_time[n];
int waiting_time[n];
int temp;
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++)
	{
          if(burst_time[i]>burst_time[j])
	  {
               temp=burst_time[j];
	       burst_time[j]=burst_time[i];
	       burst_time[i]=temp;
	       

	       temp=process[j];
	       process[j]=process[i];
	       process[i]=temp;

	  }
	}
}
call_average(burst_time,process,waiting_time,turn_time,n);
	return 0;
}
