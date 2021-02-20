#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void turn_around_time(int process[],int burst_time[],int turn_time[],int n)
{
	int curr=0;
	for(int i=0;i<n;i++){
		turn_time[process[i]-1]=burst_time[process[i]-1]+curr;
	         curr=turn_time[process[i]-1];
}
	
}
void waitning_time(int process[],int turn_time[],int n,int waiting_time_arr[])
{
	for(int i=0;i<n;i++)
		waiting_time_arr[process[i]-1]=turn_time[process[i]-1];

}

void cal_average_time(int process[],int n,int burst_time[],int turn_time[],int waiting_time_arr[]){

turn_around_time(process,burst_time,turn_time,n);
waitning_time(process,turn_time,n,waiting_time_arr);

for(int i=0;i<n;i++)
	waiting_time_arr[process[i]-1]=turn_time[process[i]-1]-burst_time[process[i]-1];

printf("Process ID	Burst Time	Turn Around Time		Waiting Time \n");
for(int i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\n",process[i],burst_time[i],turn_time[i],waiting_time_arr[i]);
}
int sum=0;
for(int i=0;i<n;i++)
sum+=waiting_time_arr[i];
printf("Average waiting time is %f\n",(double(sum)/n));

}

int main()
{
	int n=3;
int process[]={1,2,3};
int burst_time[]={7,2,4};
int turn_time[n];
int waiting_time_arr[n];


cal_average_time(process,n,burst_time,turn_time,waiting_time_arr);

	return 0;
}
