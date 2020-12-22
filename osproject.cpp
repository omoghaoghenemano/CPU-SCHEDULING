#include <iostream>
#define SIZE 10
using namespace std;
struct Data{
	int BurstTime;
	int ArrivalTime;
	int waitingTime;
	int Priority;
	int turnAround;
}c[SIZE];


int enterTIME();
int SwitchN();
int SwitchSch();
int calcFOFO();
void SJF();
void swap(int, int);
void prioritySc();

int main(){
	struct Data a;
	SwitchN();

		
		
		

}


int SwitchSch(){
	//credting a swtich for scheduling method
	cout<<"-----------------------------"<<endl;
	cout<<" --ENTER A Scheduling Method--"<<endl;
	cout<<"1.First Come, First Served Scheduling"<<endl;
	cout<<"2.Shortest-Job-First Scheduling"<<endl;
	cout<<"3.Prioty Scheduling"<<endl;
	cout<<"4.Round-Robin Scheduling"<<endl;
	
}
void prioritySc(){
	 int p[20],i,j,n,a,temp,averagewaitingTime,avg_tat;
				      int waiting[20];
				      
				      float total = 0;
				      cout<<"enter number of process";
				      cin>>n;
				      for(int i = 0; i<n; i++){
				      	cout<<"p["<<i+1<<"]";
				      	cout<<"burst time";
				      	cin>>c[i].BurstTime;
				      	cout<<"priority";
				      	cin>>c[i].Priority;
				      	p[i]=i+1;
					  }
					  for(i=0; i < n; i++){
					  	a=i;
					  	for(j=i+1;j<n;j++){
					  		if(c[j].Priority<c[a].Priority)
					  		a=j;
						  }
						  temp=c[i].Priority;
						  c[i].Priority = c[a].Priority;
						  c[a].Priority = temp;
						  
						  temp = c[i].BurstTime;
						  c[i].BurstTime = c[a].BurstTime;
						  c[a].BurstTime= temp;
						  
						  temp = p[i];
						  p[i] = p[a];
						  p[a] = temp;
					  }
					  waiting[0]=0;
					  for(i=1;i<n;i++){
					  	waiting[i]=0;
					  	for(j=0;j<i;j++)
					  waiting[i]+=c[j].BurstTime;
					  	total+=waiting[i];
					  }
					  averagewaitingTime=total/n;
					  total = 0;
					  	cout<<"============================Scheduling chart==============================="<<endl;
					  cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time"<<endl;
					  for(i=0;i<n;i++){
					  	c[i].turnAround=c[i].BurstTime+waiting[i];
					  	total+=c[i].turnAround;
					  	cout<<"\n p["<<p[i]<<"]"<<"\t\t"<<c[i].BurstTime<<"\t\t"<<waiting[i]<<"\t\t"<<c[i].turnAround<<endl;
					  }
					   avg_tat=total/n;
					   cout<<"avg waiting"<<averagewaitingTime;
					   cout<<"avg turn around"<<avg_tat;
	
}
void SJF(){
	int n, pos,temp,p[20],wait[20];
		float averagetotal, total, averagetat;
		cout<<"Please enter a processing number";
		cin>>n;
		cout<<"enter burst time"<<endl;
		for(int i = 0; i<n; i++){
		cout<<"p="<<i+1<<":";
									
		cin>>c[i].BurstTime;
		p[i]=i+1;
								        
		}
		for(int i = 0 ; i<n; i++){
				pos = i;
							
							
            for(int j=i+1;j<n;j++){
               if(c[j].BurstTime<c[pos].BurstTime){
								
                    pos=j;
                    }
                            		//check line later for error
							 
								
			}
			temp = c[i].BurstTime;
			 c[i].BurstTime = c[pos].BurstTime;
			c[pos].BurstTime = temp;
			temp = p[i];
			p[i] = p[pos];
			p[pos] = temp;

			}
			wait[0] = 0;
			for(int i = 1 ; i <n; i++){
				wait[i] = 0;
				for(int j = 0; j < i ; j++)
							
					wait[i] += c[j].BurstTime;
								
								
							
				total+=	wait[i];
				}
						
				averagetotal = total/n;
				total=0;
				cout<<"============================Scheduling chart==============================="<<endl;
				cout<<"\n process\tBurst Time\twaiting Time\t turnaroundtime";
				for(int i=0;i<n;i++){
						  	
			c[i].turnAround = c[i].BurstTime + wait[i];
					total += c[i].turnAround;
					cout<<"\np "<<p[i]<<"\t\t"<<c[i].BurstTime<<"\t\t"<<wait[i]<<"\t\t"<<c[i].turnAround<<endl;
						  	
				}
				averagetat = (float)total/n;
				cout<<"average waiting time is "<<averagetotal<<endl;
				cout<<"average turn Around time  is"<<	  averagetat<<endl;
				
	
}

int SwitchN(){
	int a;
		 
	struct Data c[SIZE];
	cout<<"--------->CPU Schedular Simulator<--------->"<<endl;
	cout<<"1) Scheduling Method"<<endl;
	cout<<"2) preemptive Mode"<<endl;
	cout<<"3) Non-preemptive Mode"<<endl;
	cout<<"4) show Result"<<endl;
	cout<<"5) End Program"<<endl;
	cout<<"Option"<<endl;
	cin>>a;
	if(a == 1){
			SwitchSch();
		 
			int decision;
			cin>>decision;
			
			if(decision==1){
				int n;int waitingtime ;int waiting[20] ;float avg; int sum;
			
			cout<<"please enter number of process"<<endl;
	                  	cin>>n;
		                cout<<"Enter Burst Time for each process"<<"=";
	                   	for(int i = 0 ; i < n ; i++){
			            
		                cout<<"process("<<i+1<<")";
		             	
		            	cin>>c[i].BurstTime;
		            	
		             	
		            }
		            cout<<"\n process\tBurst Time\twaiting Time";
		            
                      	for(int i = 0; i < n; i++){
		              		waiting[i] = c[i-1].BurstTime+ waiting[i-1];
		              		waitingtime = waiting[i];
		              		
		              		
		              		//printing out the waitingtime , burstime
		              		
		              		cout<<"\nP("<<i+1<<"]"<<"\t\t"<<c[i].BurstTime<<"\t\t"<<waitingtime<<endl;
		              		//calculating the  sum
		              		sum += waitingtime;
		              		
		              		
		              		
		              	}
		              	avg = sum/n;
		              	cout<<"\naverage of waiting time"<<avg;
		               
		              	
		              		
		              	}
		              	
		              
		            
		             
		              	
						
						if(decision == 2){
							SJF();
									
				}
				      if(decision == 3){
				      	prioritySc();
				     
					  }
					  if(decision == 4){
					  	int count,j,n,time,remain,flag=0,time_quantum;
					  	int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
					  	cout<<"Enter a Total Process";
					  	cin>>n;
					  	remain = n;
					  	for(count=0; count<n; count++){
					  		cout<<"Enter arrival time and burst time for process "<<count+1<<endl;
					  		
						   cin>>c[count].ArrivalTime;
						   cin>>c[count].BurstTime;
						   rt[count] = c[count].BurstTime;
						   
						  }
						  cout<<"enter time quantum";
						  cin>>time_quantum;
						  cout<<"\n\n Process\t Turnaround \t waiting time"<<endl;
						  for(time = 0, count = 0; remain!=0;){
						  	if(rt[count]<=time_quantum && rt[count]>0){
						  		time+=rt[count];
						  		rt[count]=0;
						  		flag=1;
							  }
							  else if(rt[count]>0){
							  	rt[count]-=time_quantum;
							  	time+=time_quantum;
							  }
							  if(rt[count]==0 && flag==1){
							  	remain--;
							  	cout<<"\n p["<<count+1<<"]"<<"\t\t"<<time-c[count].ArrivalTime<<"\t\t"<<time-c[count].ArrivalTime-c[count].BurstTime<<endl;
							  	wait_time+=time-c[count].ArrivalTime-c[count].BurstTime;
							  	turnaround_time+=time-c[count].ArrivalTime;
							  	flag=0;
							  }
							  if(count==n-1)
							  count=0;
							  else if(c[count+1].ArrivalTime)
							  count ++;
							  else
							  count=0;
						  }
						  cout<<"\n Average waiting time"<<wait_time*1.0/n<<endl;
						  cout<<"\n average turnaround time"<<turnaround_time*1.0/n<<endl;
						  
					  }
					  				  
					}
					cin.ignore();cin.get();
					return 0;
					
		}
		             
		
	

	   
	            
	            
		
	
	
	
	
	
	



	
	

