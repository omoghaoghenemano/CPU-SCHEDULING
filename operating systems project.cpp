
#include <iostream>
#define SIZE 10
using namespace std;
struct Data{
	int BurstTime;
	int ArrivalTime;
	int Priority;
}c[SIZE];


int enterTIME();
int SwitchN();
int SwitchSch();
int calcFOFO();

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


int SwitchN(){
	int a;
	cout<<"--------->CPU Schedular Simulator<--------->"<<endl;
	cout<<"1) Scheduling Method"<<endl;
	cout<<"2) preemptive Mode"<<endl;
	cout<<"3) Non-preemptive Mode"<<endl;
	cout<<"4) show Result"<<endl;
	cout<<"5) End Program"<<endl;
	cout<<"Option"<<endl;
	cin>>a;
	switch(a){
		
		case 1:
			//added the schedule switch
			SwitchSch();
		 int decision;
			
			cin>>decision;
			switch(decision){
				case 1: 
					int n;int waitingtime ;int waiting[n] ;float avg; int sum;
				
		 
	                	cout<<"please enter number of process"<<endl;
	                  	cin>>n;
		                cout<<"Enter Burst Time for each process"<<"=";
	                   	for(int i = 0 ; i < n ; i++){
			            
		                cout<<"process("<<i+1<<")";
		             	
		            	cin>>c[i].BurstTime;
		            	
		             	
		            }
		            cout<<"\n process\t\Burst Time\twaiting Time";
		            
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
		              	break;
		              	
		              	
	            
	        
	            
	                 
	
			
			
	
		}
		
	}
	
	
	
	
	
}


	
	

