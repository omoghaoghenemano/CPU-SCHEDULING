#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<deque>
#include<fstream>
#define LINE_MAX 3000
//Created by Oghenemano omogha


using namespace std;

struct node{
       int id,
           arrive,
           burst,
           priority,
           waiting,
           turnaroundtime,
           processno;
           
  
       node() : id(0), arrive(0), burst(0), priority(0), waiting(0), turnaroundtime(0), processno(0){};
};

class CPU{
 
      
   public:
       CPU(){};
       void swappingval(deque<node>::iterator num1, deque<node>::iterator num2);
       void FirstComeFirstServe(int process);
       void shortestjobfirstNP(int process);
       void Enterval(node data);
       void PriorityNonPremptive(int process);
       void RoundRobin(int quantum, int process);
       int shortestjobfirstpremptive(int process);
       void prioritypremptive(int process);
      
       void displayOutput();
       
      
         
	private:
       deque<node> Processid;
       deque<node> Processchange;
       deque<node> make;
       vector<node>completed;
       vector<node>compared;
       deque<node> burstProcess;
      
};

int main(){
 
   
  
   CPU show;
  
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
 if( remove( "output.txt" ) != 0 )
    perror( "Error deleting file" );
  else
    puts( "Output file cleared automatically" );
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
    			cout<<"2) Shortest-Job-First Scheduling:"<<endl;
    			cout<<"3) Priority Scheduling:"<<endl;
    			cout<<"4) Round-Robin Scheduling:"<<endl;
    			cout<<"option"<<endl;
    			 int option;
    			 cin>>option;
    			if(option == 1){
    				cout<<"output for firstcome first serve is writen in file"<<endl;
    				show.FirstComeFirstServe(process);
				}
				else if(option == 2){
					cout<<"output for shortest job is writen in file"<<endl;
					show.shortestjobfirstNP(process);
				  
					
				}
				else if(option == 3){
					cout<<"output for Priority is writen in file"<<endl;
					show.PriorityNonPremptive(process);
				}
				else if(option == 4){
				 cout<<"output for round robin is writen in file"<<endl;
					show.RoundRobin(quantun, process);
					
				}
    		
    			break;
    		case 2: 
    		int prem;
    		cout<<"premptive shedule"<<endl;
		    cout<<"1) ShortJOB premeptive"<<endl;
		    cout<<"2) Priority premeptive"<<endl;
		 cin>>prem;
		    if(prem==1){
		    	cout<<"Output for shortjob premeptive is written in a file"<<endl;
		    	show.shortestjobfirstpremptive(process);
			}
			if(prem==2){
				cout<<"Output for premptive is Written in a File "<<endl;
				show.prioritypremptive(process);
				
			}
			     
				 	
			     break;  
			 
			 case 3:
			 	cout<<"non preemptive outputs displayed in the file"<<endl;
			 	  
			     	show.FirstComeFirstServe(process);
			     	show.shortestjobfirstNP(process);
			     	show.PriorityNonPremptive(process);
			     	show.RoundRobin(quantun, process);
			     	
			        break;
			 	
			 	
			 	case 4: 
			 	 show.displayOutput();
			 	break;
			 	
			 	case 5:
			 		show.displayOutput();
			 		exit(1);
		}
    	
	}
  
  
 
  
   
   return 0;
}
void CPU::displayOutput(){
	ifstream file;
	char g[1000];
	
	file.open("output.txt");
	if(!file){
		cout<<"error opening the file"<<endl;
		exit(0);
	}
	cout<<endl;
	while(file.eof()==0){
			
		file>>g;
	
		cout<<g<<" "<<endl;
	}
	cout<<"\n";
	file.close();
}





void CPU::swappingval(deque<node>::iterator num1, deque<node>::iterator num2){
   deque<node>::iterator temp = num1;
   num1 = num2;
   num2 = temp;
}


bool sortArrival(const node a, const node b){
   return a.arrive < b.arrive;
}
bool sortProcess(const node a, const node b){
	return a.id < b.id;
}
void CPU::Enterval(node data){
  
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

void CPU::FirstComeFirstServe(int process){
  
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
       ofstream myfile;
       if(!myfile){
       	myfile.open("output.txt");
       	
	   }
	   else {
	   
	     myfile.open("output.txt",ios::app);
	 }
       
       myfile<<"------------------------"<<endl;
       myfile << " First Come First Served: " << endl;
       
       average = (float)waitingtime/process;
   
   
  
  
      for (int i = 0; i < completed.size(); i++){
       myfile << "P" << completed[i].id <<":" << completed[i].waiting << endl;
   }
    myfile<<"Average waiting time:"<<average;
    myfile<< endl;
   
      
      
       for (num = Processid.begin(); num != Processid.end(); num++){
           num->waiting = 0;
           num->turnaroundtime = 0;
       }
      
       completed.clear();
       myfile.close();
}


void CPU::RoundRobin(int quantum, int process){
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
    ofstream myfile2;
       if(!myfile2){
       	myfile2.open("output.txt");
       	
	   }
	   else {
	   
	     myfile2.open("output.txt",ios::app);
	 }
        myfile2<<"------------------------"<<endl;
   myfile2<< "RoundRobinScheduling–time_quantum=2:" << endl;
    average = (float)waitingtime/process;
   
   

  
      for (int i = 0; i < completed.size(); i++){
       myfile2<< "P" << completed[i].id <<":" << completed[i].waiting << endl;
   }
    myfile2<<"Average waiting time:"<<average;
   myfile2<< endl;
   myfile2.close();
  
   
}
void CPU::PriorityNonPremptive(int process){
  
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
  

  
   
  ofstream myfile4;
  
    average = (float)waitingtime/process;
       if(!myfile4){
       	myfile4.open("output.txt");
       	
	   }
	   else {
	   
	     myfile4.open("output.txt",ios::app);
	 
	 }
	  myfile4<<"------------------------"<<endl;
    myfile4<<"Priority Scheduling Non-Preemptive: " << endl;
  
      for (int i = 0; i < completed.size(); i++){
       myfile4<< "P" << completed[i].id <<":" << completed[i].waiting << endl;
   }
    myfile4<<"Average waiting time:"<<average;
   myfile4<< endl;
   myfile4.close();
   
  
   for (num = Processid.begin(); num != Processid.end(); num++){
           num->waiting = 0;
           num->turnaroundtime = 0;
       }
  
   completed.clear();
}
void CPU::shortestjobfirstNP(int process){


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
    average = waitingtime/process;
   ofstream myfile1;
       if(!myfile1){
       	myfile1.open("output.txt");
       	
	   }
	   else {
	   
	     myfile1.open("output.txt",ios::app);
	 }
       myfile1<<"------------------------"<<endl;
   
   myfile1<<"\n ShortestJobFirstNonPreemptive:" << endl;
  
      for (int i = 0; i < completed.size(); i++){
       myfile1<<"P" << completed[i].id <<":" << completed[i].waiting << endl;
   }
    myfile1<<"\n Average waiting time"<<average<<endl;
   myfile1<<endl;
   
   myfile1.close();
   for (num = Processid.begin(); num != Processid.end(); num++){
           num->waiting = 0;
           num->turnaroundtime = 0;
           
       }
       
      
   completed.clear();
}

void CPU::prioritypremptive(int process){
	 int total = 0, timecalc = 0; int waitingtime = 0, average = 0;
	int originalburst[10];
	
	for (deque<node>::iterator currentnum = Processid.begin(); currentnum != Processid.end(); currentnum++){
		originalburst[currentnum->id] = currentnum->burst;
	}
	
	sort(Processid.begin(), Processid.end(), sortArrival);
	
	 deque<node>::iterator num;
	deque<node>::iterator currentnum;
	deque<node>::iterator smallestnum;
	for (num = Processid.begin(); num != Processid.end(); num++){
		
		deque<node>::iterator temp = num;
		deque<node>::iterator next = ++temp; 
		if (num == Processid.begin()){
			timecalc += next->arrive - num->arrive; 
			total += timecalc;
			num->burst -= timecalc;
		}
		else if (next == Processid.end()){  
			break;
		}
		else{
			sort(burstProcess.begin(), burstProcess.end(), sortBurst);
			
			for (currentnum = burstProcess.begin(); currentnum != burstProcess.end(); currentnum++){
				if (currentnum->burst == 0){
					burstProcess.erase(currentnum);
					continue;
				}
				else if (num->burst > currentnum->burst && currentnum->arrive <= total){
					smallestnum = currentnum; 
					break;
			    }
			    else{
			    	smallestnum = num;
				}
		    }
		    timecalc += 1;
		 	timecalc += next->arrive - num->arrive; 
		 	total += timecalc; 
		 	smallestnum->burst -= timecalc; 
		 	
		 
		 	if (smallestnum == num){
		 		for (currentnum = burstProcess.begin(); currentnum != burstProcess.end(); currentnum++){
		 			int temptime = smallestnum->burst;
		 			if (currentnum->burst == temptime + timecalc)
		 				currentnum->burst -= timecalc ;
				 }
			 }
			else{
			 	for (currentnum = Processid.begin(); currentnum != Processid.end(); currentnum++){
		 			int temptime = smallestnum->burst;
		 			if (currentnum->burst == temptime + timecalc)
		 				currentnum->burst -= timecalc;
				 }
			 }
		 	
		 	if (smallestnum->burst == 0){  
			   	smallestnum->waiting += total - smallestnum->arrive - originalburst[smallestnum->id];
			   	smallestnum->turnaroundtime += total - smallestnum->arrive;
		 		completed.push_back((*smallestnum)); 
			 }
		}	
	}
		sort(burstProcess.begin(), burstProcess.end(), sortPriority);
		
		for (deque<node>::iterator currentnum = burstProcess.begin(); currentnum != burstProcess.end(); currentnum++){
			total += currentnum->burst;
			currentnum->waiting += total - currentnum->arrive - originalburst[currentnum->id];
			currentnum->turnaroundtime += total - currentnum->arrive;
			waitingtime+=currentnum->waiting;
			
			completed.push_back((*currentnum));	
		}
		
   ofstream myfile13;
   average = waitingtime/process;
       if(!myfile13){
       	myfile13.open("output.txt");
       	
	   }
	   else {
	   
	     myfile13.open("output.txt",ios::app);
	 }
       myfile13<<"------------------------"<<endl;
   
   myfile13<<"\n Priority premptive:" << endl;
  
      for (int i = 0; i < completed.size(); i++){
       myfile13<<"P" << completed[i].id <<":" << completed[i].waiting << endl;
   }
    myfile13<<"\n Average waiting time"<<average<<endl;

   
   myfile13.close();


	
	
	
	for (num = Processid.begin(); num != Processid.end(); num++){
			num->waiting = 0;
			num->turnaroundtime = 0;
		}
	
	completed.clear();
	
}
int CPU::shortestjobfirstpremptive(int process){
	/*
		 int total = 0, timecalc = 0; int waitingtime = 0, average = 0;
	int originalburst[10];
	
	for (deque<node>::iterator currentnum = Processid.begin(); currentnum != Processid.end(); currentnum++){
		originalburst[currentnum->id] = currentnum->burst;
	}
	
	sort(Processid.begin(), Processid.end(), sortArrival);
	
	 deque<node>::iterator num;
	deque<node>::iterator currentnum;
	deque<node>::iterator smallestnum;
	for (num = Processid.begin(); num != Processid.end(); num++){
		
		deque<node>::iterator temp = num;
		deque<node>::iterator next = ++temp; 
		if (num == Processid.begin()){
			timecalc += next->arrive - num->arrive; 
			total += timecalc;
			num->burst -= timecalc;
		}
		else if (next == Processid.end()){  
			break;
		}
		else{
			sort(burstProcess.begin(), burstProcess.end(), sortBurst);
			
			for (currentnum = burstProcess.begin(); currentnum != burstProcess.end(); currentnum++){
				if (currentnum->burst == 0){
					burstProcess.erase(currentnum);
					continue;
				}
				else if (num->burst > currentnum->burst && currentnum->arrive <= total){
					smallestnum = currentnum; 
					break;
			    }
			    else{
			    	smallestnum = num;
				}
		    }
		    timecalc +=1;
		 	timecalc += next->arrive - num->arrive; 
		 	total += timecalc; 
		 	smallestnum->burst -= timecalc; 
		 	
		 
		 	if (smallestnum == num){
		 		for (currentnum = burstProcess.begin(); currentnum != burstProcess.end(); currentnum++){
		 			int temptime = smallestnum->burst;
		 			if (currentnum->burst == temptime + timecalc)
		 				currentnum->burst -= timecalc ;
				 }
			 }
			else{
			 	for (currentnum = Processid.begin(); currentnum != Processid.end(); currentnum++){
		 			int temptime = smallestnum->burst;
		 			if (currentnum->burst == temptime + timecalc)
		 				currentnum->burst -= timecalc;
				 }
			 }
		 	
		 	if (smallestnum->burst == 0){  
			   	smallestnum->waiting += total - smallestnum->arrive - originalburst[smallestnum->id];
			   	smallestnum->turnaroundtime += total - smallestnum->arrive;
		 		completed.push_back((*smallestnum)); 
			 }
		}	
	}
		sort(burstProcess.begin(), burstProcess.end(), sortBurst);
		
		for (deque<node>::iterator currentnum = burstProcess.begin(); currentnum != burstProcess.end(); currentnum++){
			total += currentnum->burst;
			currentnum->waiting += total - currentnum->arrive - originalburst[currentnum->id];
			currentnum->turnaroundtime += total - currentnum->arrive;
			waitingtime+=currentnum->waiting;
			
			completed.push_back((*currentnum));	
		}
	
   fstream myfile12;
   	average = waitingtime/process;
       if(!myfile12){
       	myfile12.open("output.txt");
       	
	   }
	   else {
	   
	     myfile12.open("output.txt",ios::app);
	 }
       myfile12<<"------------------------"<<endl;
   
   myfile12<<"\n Priority premptive:" << endl;
  
      for (int i = 0; i < completed.size(); i++){
       myfile12<<"P" << completed[i].id <<":" << completed[i].waiting << endl;
   }
    myfile12<<"\n Average waiting time"<<average<<endl;
   myfile12<<endl;
   
   myfile12.close();


	
	
	
	for (num = Processid.begin(); num != Processid.end(); num++){
			num->waiting = 0;
			num->turnaroundtime = 0;
		}
	
	completed.clear();
   /*/

	
}
 
	 	



  
