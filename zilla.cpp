#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<deque>
#define LINE_MAX 30

using namespace std;

struct node{
       int id,
           arrive,
           burst,
           priority,
           waiting,
           turnaroundtime;
          
           
  
       node() : id(0), arrive(0), burst(0), priority(0), waiting(0), turnaroundtime(0){};
};

class Method{
 
      
   public:
       Method(){};
       void swappingval(deque<node>::iterator num1, deque<node>::iterator num2);
       void display_original();
       void Display();
       void FirstComeFirstServe(int process);
       void shortestjobfirstNP(int process);
       void Enterval(node data);
       void PriorityNonPremptive(int process);
       void RoundRobin(int quantum, int process);
      
         
	private:
       deque<node> Processid;
       deque<node> Processchange;
       vector<node>completed;
       deque<node> burstProcess;
      
};

int main(){
 
   
  
   Method show;
  
    struct node data;
    FILE *fp;
   char line[LINE_MAX];
  unsigned int num[3];
    int process = 0;
  if ((fp = fopen("input.txt", "r")) == NULL)
        return 0 ;
  while (fgets(line, LINE_MAX, fp) != NULL) {
        sscanf(line,"%d:%d:%d\n",&num[0],&num[1],&num[2]);
        data.id= process+=1;
        data.burst = num[0];
           data.arrive = num[1];
           data.priority = num[2];
           show.Enterval(data);
}
fclose(fp);
 int choice;
    while(1){
    	
    	cout<<"............................................."<<endl;
    	cout<<"CPU SCHEDULER SIMULATOR"<<endl;
    	cout<<"1) Scheduling Method"<<endl;
    	cout<<"2) Preemptive Mode"<<endl;
    	cout<<"3) Non-Preemptive Mode"<<endl;
    	cout<<"4) Show Result"<<endl;
    	cout<<"5) End Program"<<endl;
    	cout<<"Option"<<endl;
    		int quantun = 2;
    	cin>>choice;
    	switch(choice){
    		case 1:
    			cout<<"1) First come, First Served Scheduling;"<<endl;
    			cout<<"2) Shortest-Job-First Scheduling "<<endl;
    			cout<<"3) Priority Scheduling"<<endl;
    			cout<<"4) Round-Robin Scheduling"<<endl;
    			cout<<"option"<<endl;
    			 int option;
    			 cin>>option;
    			if(option == 1){
    				show.FirstComeFirstServe(process);
				}
				else if(option == 2){
					show.shortestjobfirstNP(process);
				  
					
				}
				else if(option == 3){
					show.PriorityNonPremptive(process);
				}
				else if(option == 4){
				
					show.RoundRobin(quantun, process);
					
				}
    		
    			break;
    		case 2: 
			 cout<<"non premeptive"<<endl;	
			     break;  
			 
			 case 3:
			 	cout<<"preemptive"<<endl;
			 	  
			     	show.FirstComeFirstServe(process);
			     	show.shortestjobfirstNP(process);
			     	show.PriorityNonPremptive(process);
			     	show.RoundRobin(quantun, process);
			     	
			        break;
			 	
			 	
			 	case 4: cout<<"show result"<<endl;
			 	 show.display_original(); 
			 	break;
			 	
			 	case 5:
			 		exit(1);
		}
    	
	}
  
  
 
  
   
   return 0;
}
void Method::Display(){
  
   cout << "Process Waiting Times:" <<endl;
  
   for (int i = 0; i < completed.size(); i++){
       cout << "P" << completed[i].id <<":" << " "<< completed[i].waiting << endl;
   }
   cout << endl;
}



void Method::display_original(){
  
   cout  << "Process" << endl;
  
   for (int i = 0; i < Processid.size(); i++){
       cout  <<"P" << Processid[i].id <<" "<<Processid[i].arrive <<" "<< Processid[i].burst << " "<< Processid[i].priority << endl;
   }
   cout << endl;
}

void Method::swappingval(deque<node>::iterator num1, deque<node>::iterator num2){
   deque<node>::iterator temp = num1;
   num1 = num2;
   num2 = temp;
}


bool sortArrival(const node a, const node b){
   return a.arrive < b.arrive;
}

void Method::Enterval(node data){
  
   Processid.push_back(data);
   Processchange.push_back(data);
   burstProcess.push_back(data);
}

bool sortBurst(const node a, const node b){
   return a.burst < b.burst;
}

bool sortPriority(const node a, const node b){
   return a.priority < b.priority;
}

void Method::FirstComeFirstServe(int process){
  
   sort(Processid.begin(), Processid.end(), sortArrival);
   int time = 0;
   float average = 0, waitingtime;
   deque<node>::iterator num;
   for (num = Processid.begin(); num != Processid.end(); num++){
       time += num->burst;
       num->waiting = time - num->arrive - num->burst;
       num->turnaroundtime = time - num->arrive;
       waitingtime += num->waiting;
       
       completed.push_back((*num));
   }
       cout << " First Come First Served: " << endl;
       
       average = (float)waitingtime/process;
   
   
  
  
      for (int i = 0; i < completed.size(); i++){
       cout << "P" << completed[i].id <<":" << " "<< completed[i].waiting << endl;
   }
    cout<<"Average waiting time:"<<average;
   cout << endl;
   
      
      
       for (num = Processid.begin(); num != Processid.end(); num++){
           num->waiting = 0;
           num->turnaroundtime = 0;
       }
      
       completed.clear();
}


void Method::RoundRobin(int quantum, int process){
   int burstmain[10];
   sort(Processchange.begin(), Processchange.end(), sortArrival);
   int time = 0; float average = 0, waitingtime = 0;
   
  
 
   for (deque<node>::iterator current = Processchange.begin(); current != Processchange.end(); current++){
       burstmain[current->id] = current->burst;
   }
  
   deque<node>::iterator num;
   for (num = Processchange.begin(); num != Processchange.end() ; num++){
       
       if (num->burst <= quantum){
           time += num->burst;
           num->waiting += time - num->arrive - burstmain[num->id];
           num->turnaroundtime += time - num->arrive;
           waitingtime+=num->waiting;
           completed.push_back((*num));
       }
       
       else{
           time += quantum;
           num->burst -= quantum;
           Processchange.push_back((*num));
       }
   }
   cout << "Round Robin Scheduling–time_quantum=2 : " << endl;
    average = (float)waitingtime/process;
   
   

  
      for (int i = 0; i < completed.size(); i++){
       cout << "P" << completed[i].id <<":" << " "<< completed[i].waiting << endl;
   }
    cout<<"Average waiting time:"<<average;
   cout << endl;
   
  
   
}
void Method::PriorityNonPremptive(int process){
  
sort(Processid.begin(), Processid.end(), sortArrival);
  
   deque<node>::iterator num;
   bool checked[10]; float average, waitingtime;
   deque<node>type;
   type.push_back((*Processid.begin()));
  
   int time = Processid.begin()->burst;
   Processid.begin()->waiting += time - Processid.begin()->burst - Processid.begin()->arrive;
   Processid.begin()->turnaroundtime += time - Processid.begin()->arrive;
   
   completed.push_back((*Processid.begin()));
  
    
  
   for (int i = 0; i < 10; i++){
       checked[i] = false;
   }
  
   while (type.size()){
      
       if (type.front().arrive == Processid.begin()->arrive){
           type.pop_front();
       }
      
       for (num = Processid.begin() + 1; num != Processid.end(); num++){
           
           if (num->arrive <= time && checked[num->id] == false){
               type.push_back((*num));
               checked[num->id] = true;
           }
       }
      
       sort (type.begin(), type.end(), sortPriority);
       deque<node>::iterator end = type.begin();
      
       time += end->burst;
       end->waiting += time - end->burst - end->arrive;
       end->turnaroundtime += time - end->arrive;
       waitingtime+= end->waiting;
      
       completed.push_back((*end));
      
       type.pop_front();
   }
  

  
    average = (float)waitingtime/process;
   
   
   cout << "Priority Scheduling Non-Preemptive: " << endl;
  
      for (int i = 0; i < completed.size(); i++){
       cout << "P" << completed[i].id <<":" << " "<< completed[i].waiting << endl;
   }
    cout<<"Average waiting time:"<<average;
   cout << endl;
   
  
   for (num = Processid.begin(); num != Processid.end(); num++){
           num->waiting = 0;
           num->turnaroundtime = 0;
       }
  
   completed.clear();
}
void Method::shortestjobfirstNP(int process){


   sort(Processid.begin(), Processid.end(), sortArrival);
  
   deque<node>::iterator num, start = Processid.begin();
  
  
   deque<node> type;
   type.push_back((*start));
    bool checked[10];
    float average = 0, waitingtime = 0;
   int time = start->burst;
   start->waiting += time - start->burst - start->arrive;
   start->turnaroundtime += time - start->arrive;
  
   completed.push_back((*start));
  
   
  
   for (int i = 0; i < 10; i++){
       checked[i] = false;
       
   }

   while (type.size()){
   	     
    
       if (type.front().arrive == Processid.begin()->arrive){
           type.pop_front();
       }
      
       for (num = Processid.begin() + 1; num != Processid.end(); num++){
           
           
           if (num->arrive <= time && checked[num->id] == false){
               type.push_back((*num));
               checked[num->id] = true;
           }
       }
       
       sort (type.begin(), type.end(), sortBurst);
       deque<node>::iterator end = type.begin();
      
       time += end-> burst;
       end->waiting += time - end->burst - end->arrive;
       end->turnaroundtime += time - end->arrive;
       waitingtime += end->waiting;
        
       completed.push_back((*end));
      
       type.pop_front();
   }
   
   average = (float)waitingtime/process;
   
   
   cout << "Shortest Job First NonPreemptive: " << endl;
  
      for (int i = 0; i < completed.size(); i++){
       cout << "P" << completed[i].id <<":" << completed[i].waiting << endl;
   }
    cout<<"Average waiting time:"<<average;
   cout << endl;
   
  
   for (num = Processid.begin(); num != Processid.end(); num++){
           num->waiting = 0;
           num->turnaroundtime = 0;
           
       }
       
      
   completed.clear();
}




  
