#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#define LINE_MAX 1024
#include <fstream>
using namespace std;
struct node{
int arrival;
int burst;
int processno;
int completiontime;
int priority;
int turnAround;
int waiting;
node* next;
node* prev;
};
struct node* createNode(int processes, int arrivaltime, int bursttime, int prioritytime){
struct node* temp;
temp = (struct node*) malloc(sizeof(node));
temp->processno = processes;
temp->arrival = arrivaltime;
temp->burst = bursttime;
temp->priority = prioritytime;
temp->next = NULL;
temp->prev = NULL;
return temp;
}
struct node* insertBack(struct node* header,int processes, int arrivaltime, int bursttime, int prioritytime){
struct node* temp = createNode(processes, arrivaltime,  bursttime, prioritytime);
struct node* headertemp;
if(header == NULL){
header = temp;
return header;
}

headertemp = header;
while(headertemp->next!=NULL)
headertemp = headertemp->next;
headertemp->next = temp;
temp->prev = headertemp;
return header;


}

int is_empty(struct node *header){
	if(header==NULL){
		return 1;
	
	}
	else 
	return 0;
}
struct node* sortArrival(struct node* header ){
	struct node* temp = header;
	struct node* i = temp;
	struct node* j = temp->next;
	for(i=temp; i != NULL; i = i->next){
		for(j=i->next; j != NULL; j = j->next){
			if(((i->arrival)) > ((j->arrival))){
			
			struct node* temp2 = createNode(i->processno, i->arrival, i->burst, i->priority);
			i->processno = j->processno;
			i->arrival = j->arrival;
			i->burst = j->burst;
			i->priority = j->priority;
			i->waiting = j->waiting;
			i->turnAround = j->turnAround;
			i->completiontime = j->completiontime;
			
			j->processno = temp2->processno;
			j->arrival = temp2->arrival;
			j->burst = temp2->burst;
			j->priority = temp2->priority;
				j->waiting = temp2->waiting;
			j->turnAround = temp2->turnAround;
			j->completiontime = temp2->completiontime;
		}
		}
	}
	return temp;
}
struct node* sortProcess(struct node* header){
	struct node* temp = header;
	struct node* i = temp;
	struct node* j = temp->next;
	for(i=temp; i != NULL; i = i->next){
		for(j=i->next; j!=NULL; j=j->next){
			if(((i->processno)) > ((j->processno))){
					struct node* temp2 = createNode(i->processno, i->arrival, i->burst, i->priority);
			i->processno = j->processno;
			i->arrival = j->arrival;
			i->burst = j->burst;
			i->priority = j->priority;
				i->waiting = j->waiting;
			i->turnAround = j->turnAround;
			i->completiontime = j->completiontime;
			
			j->processno = temp2->processno;
			j->arrival = temp2->arrival;
			j->burst = temp2->burst;
			j->priority = temp2->priority;
				j->waiting = temp2->waiting;
			j->turnAround = temp2->turnAround;
			j->completiontime = temp2->completiontime;
			}
			
		}
	}
}
struct node* sortBurstime(struct node* header){
		struct node* temp = header;
	struct node* i = temp;
	struct node* j = temp->next;
	int bursttime;
	int min = 0;

	for(i=temp; i != NULL; i = i->next){
		 	for(j=i->next; j != NULL; j = j->next){
		
				if(((i->burst)) < ((j->burst))){
			struct node* temp2 = createNode(i->processno, i->arrival, i->burst, i->priority);
			i->processno = j->processno;
			i->arrival = j->arrival;
			i->burst = j->burst;
			i->priority = j->priority;
		
			j->processno = temp2->processno;
			j->arrival = temp2->arrival;
			j->burst = temp2->burst;
			j->priority = temp2->priority;
			
		}
	}
     

}
return temp;
}

void display(struct node *header)

{
    if (header == NULL)
        cout << "List is empty" << endl;
        
    struct node* temp = header;

    while (temp != NULL)
    {
        
        cout<<temp->burst<<"-->";
        
        
        temp=temp->next;
        
    }
    cout << endl;
}
struct node* FCFS(struct node* header){
	int process = 0;
	float average; 
	int wt = 0;
	int currentTime = 0;
	header = sortArrival(header);
	
	struct node* temp = header;
	struct node* anothertemp = header;
	while(!is_empty(temp)){
	 process+=1;
	 
	 if(temp->arrival>currentTime){
	 	currentTime +=1;
	 
	 	 continue;
	 }
	
	
	currentTime += temp->burst;
	temp->completiontime = currentTime;
	temp->turnAround = temp->completiontime - temp->arrival;
	temp->waiting = temp->turnAround - temp->burst;
	wt+= temp->waiting;
	if(temp->next!= NULL)
		temp=temp->next;
		
		else
		break;
}
average = (float)wt/process;

sortProcess(header);
ofstream myFile("output1.txt");
myFile<<"\nScheduling method: \n";
while(!is_empty(anothertemp)){
	myFile <<"p"	<<anothertemp->processno<<":"<<anothertemp->waiting<<"ms\n";
	anothertemp = anothertemp->next;
	//display(anothertemp);
}
myFile<<"average waiting time"<<average<<"ms\n";
myFile.close();
}
void swap(struct node* head){

 node* temp = head; 
  
    // Traverse the List 
    while (temp) { 
        node* min = temp; 
        node* r = temp->next; 
        node*h = temp->next;
  
        // Traverse the unsorted sublist 
        while (r) { 
            if (min->burst > r->burst) 
                min = r; 
  
            r = r->next; 
        } 
        
        
        // Swap Data 
        int x = temp->burst; 
        temp->burst= min->burst; 
        min->burst= x; 
        temp = temp->next; 
        
        
    } 
   

}
void swap1(struct node* head){

 node* temp = head; 
  
    // Traverse the List 
    while (temp) { 
        node* min = temp; 
        node* r = temp->next; 
  
        // Traverse the unsorted sublist 
        while (r) { 
            if (min->arrival > r->arrival) 
                min = r; 
  
            r = r->next; 
        } 
  
        // Swap Data 
        int x = temp->arrival; 
        temp->arrival= min->arrival; 
        min->arrival= x; 
        temp = temp->next;
		
		 
        
        
        
    } 
   

}


struct node* SJF(struct node* header){
	int process = 0;
	float average; 
	int wt = 0;
	int currentTime = 0;
	swap(header);
	
	struct node* temp = header;
	struct node* anothertemp = header;
	while(!is_empty(temp)){
	 process+=1;
	 
	 if(temp->arrival>currentTime){
	 	currentTime +=1;
	 
	 	 continue;
	 }
	
	
	currentTime += temp->burst;
	temp->completiontime = currentTime;
	temp->turnAround = temp->completiontime - temp->arrival;
	temp->waiting = temp->turnAround - temp->burst;
	wt+= temp->waiting;
	if(temp->next!= NULL)
		temp=temp->next;
		
		else
		break;
}
average = (float)wt/process;

sortProcess(header);
ofstream myFile("output1.txt");
myFile<<"\nScheduling method: \n";
while(!is_empty(anothertemp)){
	myFile <<"p"	<<anothertemp->processno<<":"<<anothertemp->waiting<<"ms\n";
	anothertemp = anothertemp->next;
	//display(anothertemp);
}
myFile<<"average waiting time"<<average<<"ms\n";
myFile.close();
	
}

/*/
struct node* dSJF(struct node* header){
		int process = 0;
	float average; 
	int wt = 0;
	int currentTime = 0;
	
	   
	struct node* temp = header;


	
	struct node* anothertemp = header;
	while(!is_empty(temp)){
	 process+=1;

	 	 if(temp->arrival>currentTime){
	 	currentTime +=1;
	 	 
	  
	 	 continue;
	 }
	
	
    currentTime+= temp->burst;
	temp->completiontime = currentTime;
	temp->turnAround = temp->completiontime- temp->arrival;
	temp->waiting = temp->turnAround - temp->burst;
	wt+= temp->waiting + temp->arrival;
	if(temp->next!= NULL)
		temp=temp->next;
		
		else
		break;

}
average = (float)wt/process;


ofstream myFile("output1.txt");
myFile<<"\nScheduling method: \n";
while(!is_empty(anothertemp)){
	myFile <<"p"	<<anothertemp->processno<<":"<<anothertemp->waiting<<"ms\n";
	anothertemp = anothertemp->next;
	//display(anothertemp);
}
myFile<<"average waiting time"<<average<<"ms\n";
myFile.close();
	
	
}
/*/
void SJsF(struct node* header){
			struct node* result = NULL;
			struct node* temp;
	int processCount = 0;
	float totalBurstTime = 0;
	for (struct node* j=header; j != NULL; j = j->next){
		processCount++;
		totalBurstTime += j->burst;
		
}
display(header);cout << "pre sort";
for(int i=0; i < processCount; i++) {
	int min = 1000;
	struct node* temp= NULL;
	for(struct node* j=header; j != NULL; j = j->next){
		if (j->burst <= min){
		    temp = j;
		    min = j->burst;
		}
	}
		    
		    struct node* q = NULL;
		    struct node* r = NULL;
		    q = temp->next;
		    r = temp->prev;
		    if (r != NULL) {
		    	r->next = q;
			}
			
		    if (q != NULL) {
		    	q->prev = r;
			}
		

       if(result != NULL){
       	insertBack(result, temp->processno, temp->arrival, temp->burst, temp->priority);
	   } else {
	   	result = temp;
	   }
}

display(result);cout << "post sort";
int n = processCount;
    float averagetotal, total, averagetat, totalWait =0;
    total = 0;
    cout << "============================Scheduling chart===============================" << endl;
    cout << "\n process\tBurst Time\twaiting Time\t turnaroundtime";
    int wait =0;
    int count =0;
    for(struct node* c=result; c != NULL; c = c->next){
    	
    	if( count != 0) {
    		struct node* x = c;
    		while ( x->prev != NULL ) {
    		wait += x->prev ->burst;
    		x = x->prev;
			}
    			totalWait += wait;
		}
	
	      
		count +=1;
        c->turnAround =  wait + c->burst ;
        total += c->turnAround;
  
        cout << "\np " << c->processno << "\t\t" << c->burst << "\t\t" << wait<< "\t\t" << c->turnAround << endl;
   
}
    averagetat = (float)total / processCount;
    averagetotal = totalWait / n;
    cout << "average waiting time is " << averagetotal << endl;
    cout << "average turn Around time  is" << averagetat << endl;
    

    

ofstream myFile("output1.txt");
myFile<<"\nSJF method: \n";
while(!is_empty(result)){
	myFile <<"p"	<<result->processno<<":"<<result->waiting<<"ms\n";
result = result->next;
}

	display(result);

myFile.close();

}

	 
struct node* sortPriority(struct node* header){
struct node* temp = header;
	struct node* i = temp;
	struct node* j = temp->next;
	for(i=temp; i != NULL; i = i->next){
		for(j=i->next; j != NULL; j = j->next){
			if(((i->priority)) > ((j->priority+1))){
			
			struct node* temp2 = createNode(i->processno, i->arrival, i->burst, i->priority);
			i->processno = j->processno;
			i->arrival = j->arrival;
			i->burst = j->burst;
			i->priority = j->priority;
		
			j->processno = temp2->processno;
			j->arrival = temp2->arrival;
			j->burst = temp2->burst;
			j->priority = temp2->priority;
			
		}
		}
	}
	return temp;
	
}
	
    

struct node* priority(struct node* header){

	int waiting = 0;
	int total = 0;
	int averagewaiting = 0;
	int process = 0;
	int currentTime = 0;
	int wt = 0;
	int average = 0;
     header = sortArrival(header);
	struct node* temp = header;
		struct node* anothertemp = header;
	while(!is_empty(temp)){
	 process++;
	 
	 if(temp->arrival>currentTime){
	 	currentTime +=1;
	 	 
	 	
	 	
	 	 continue;
	 }
	
	int c=0; int b=0;
		
	currentTime += temp->burst;
	temp->completiontime = currentTime;
	temp->turnAround = temp->completiontime - temp->arrival;

	temp->waiting = (temp->burst + temp->arrival + temp->waiting)- temp->arrival;
	wt+= temp->waiting;
	if(temp->next!= NULL)
		temp=temp->next;
		
		else
		break;
}
average = (float)wt/process;
sortProcess(header);

ofstream myFile("output1.txt");
myFile<<"\nSmethod: \n";
while(!is_empty(anothertemp)){
	myFile <<"p"	<<anothertemp->processno<<":"<<anothertemp->waiting<<"ms\n";
	anothertemp = anothertemp->next;
	//display(anothertemp);
}
myFile<<"average waiting time"<<average<<"ms\n";
myFile.close();
		

     
}	
	
    



int main(){
	struct node* header = NULL;
	
		
		FILE *fp;
	char line[LINE_MAX];
	unsigned int num[3];
	int process = 0;

	if ((fp = fopen("input.txt", "r")) == NULL){
			cout <<"can't open file input.txt"<<endl;
			exit(1);
	}
			
	while (fgets(line, LINE_MAX, fp) != NULL) {
		process++;
		
		sscanf(line,"%d:%d:%d\n",&num[0],&num[1],&num[2]);
		header = insertBack(header, process, num[1], num[0], num[2]);
		cout<<num[0];
		
		
				
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
    				FCFS(header);
				}
				else if(option == 2){
					SJF(header);
				     display(header);
					
				}
				else if(option == 3){
					priority(header);
				}
				else if(option == 4){
					
				}
    		
    			break;
    		case 2: 
			 cout<<"non premeptive"<<endl;	
			 
			 break;
			 
			 case 3:
			 	cout<<"preemptive"<<endl;
			 	break;
			 	
			 	case 4: cout<<"show result"<<endl;
			 	break;
			 	
			 	case 5:
			 		exit(1);
		}
    	
	}




        
	
return 0;
}
