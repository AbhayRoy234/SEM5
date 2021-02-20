#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


void cal_turn_around_time(int process[],int burst1_time[],int turn_time[],int n,int qunatum_time)
{
	int burst_time[n];
	for(int i=0;i<n;i++)
		burst_time[i]=burst1_time[i];
	int max=burst_time[0];
	for(int i=1;i<n;i++)
		if(max<burst_time[i])
			max=burst_time[i];

	int curr=0;
	for(int j=0;j<(max/qunatum_time)+1;j++){
		for(int i=0;i<n;i++){
		  if(burst_time[i]!=0){
			   if(burst_time[i]<=qunatum_time){
				   turn_time[i]=curr+burst_time[i];
			           curr+=burst_time[i];
				   burst_time[i]=0;
                                  
			   }
			   else{ 
				    burst_time[i]-=qunatum_time;
				    curr+=qunatum_time;
			       }
		}
	     }
	}
}

void cal_waiting_time(int burst_time[],int waiting_time[],int turn_time[],int n){

	for(int i=0;i<n;i++)
	{
		waiting_time[i]=turn_time[i]-burst_time[i];
	}
}
void call_average(int burst_time[],int process[],int waiting_time[],int turn_time[],int n,int quantum_time)
{
double sum=0,sum1=0;
cal_turn_around_time(process,burst_time,turn_time,n,quantum_time);
cal_waiting_time(burst_time,waiting_time,turn_time,n);
for(int i=0;i<n;i++)
{
sum+=waiting_time[i];
sum1+=turn_time[i];
}
printf("process id\tBurst Time\tTurnAroud Time\t Waiting Time\n");
for(int i=0;i<n;i++)
{
	printf("%d\t\t%d\t\t%d\t\t%d\n",process[i],burst_time[i],turn_time[i],waiting_time[i]);
}
printf("Average Waiting Time is %f\n",sum/(float)n);
printf("Average turn around  Time is %f\n",sum1/(float)n);

}

int main()
{
int process[]={0,1,2};
int n=sizeof(process)/sizeof(process[0]);
int burst_time[]={24,3,3};
//int priority[]={1,2,3,4,5};
int turn_time[n];
int waiting_time[n];
int qunatum_time;
printf("Enter the quantum Time\n");
scanf("%d",&qunatum_time);
call_average(burst_time,process,waiting_time,turn_time,n,qunatum_time);
	return 0;
}
