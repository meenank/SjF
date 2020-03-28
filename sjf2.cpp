     /*Question:-
       Consider a scheduler which schedules the job by considering the arrival time of the
       processes where arrival time if given as 0 is discarded or displayed as error. The scheduler
       implements the shortest job first scheduling policy, but checks the queue of the processes after
       the every process terminates and time taken for checking and arranging the process according to
       the shortest job is 2 time unit. Compute the waiting time, turnaround time and average waiting
       time and turnaround time of the processes. Also compute the total time taken by the processor to
       compute all the jobs.
       - unit time here by default is taken as MilliSeconds (ms)
       */
       /*sample test case:-
         p.id   A.T    B.T
         1      0       6 -> this process is not considered because arival time is 0 as stated in the question
         2      3       2
         3      5       1
         4      9       7
         5      10      5
         6      12      3
         7      14      4
         8      16      5
         9      17      7
         10     19      2
       */
#include<iostream>
#include<algorithm>
using namespace std;
//declaring all global variables and data structures...
int i,j,n,k;
float y=0, x=0,avg_wait=0, avg_turn=0, tot_time=0;
int arival[50], burst[50], proc[50];
float wait[50], turn[50];
// no return type function to calcuate "waiting time and average waiting time of processes"...
void waiting_time()
    {
        /* waiting time of first process is 0 because it is the shortest
           and from next process scheduler takes 2 time unit to search it 
           and run that second shortest process
        */
        wait[0]=0;
        for(i=1; i<n; i++)
        {
            wait[i]=wait[i-1]+burst[i-1]+2;
            /* (+2) is there because waiting time is increased while schedular searches for nexxt ahortest job
              in the queue after every job terminates*/
            y+=float(wait[i]);
        }
         avg_wait=y/n;
        
    }
 // no return type function to calculate "Turn around time and average turn around time of processes"...
void turnaround_time()
{
    
    for(i=0; i<n; i++)
    {
        turn[i]=burst[i]+wait[i];
        x+=float(turn[i]);
    }
     avg_turn=x/n;
}
// no return type function to calculate "total time taken"...
void total_time()
{
    for(i=0; i<n; i++)
    {
        tot_time+=float(burst[i]);
    }
}
int main()
{ 
    cout<<"enter no.of requirements/processes: ";
    cin>>n;   
    for(i=0; i<n; i++)
    {
        cout<<"enter process id: ";
        cin>>proc[i];
        cout<<"enter arival time of process P"<<i+1<<": ";
        cin>>k;
        if(k==0)
        {     
            cout<<"Error! burst time is set to 0, as this process does not validate"<<endl;
            burst[i]=0;
            continue;
        }
        else if(k!=0 && k>0)
        {
            arival[i]=k;
        }
        cout<<"enter burst time of process P"<<i+1<<": ";
        cin>>burst[i];
    }
    for(j=0; j<n; j++)
    {
        for(i=j+1; i<n; i++)
        {
            if(burst[i]<burst[j])
            {
                swap(arival[i], arival[j]);
                swap(burst[i], burst[j]);
                swap(proc[i], proc[j]);
            }
        }
    }
    // calling functions...
    waiting_time();
    turnaround_time();
    total_time();
    cout<<endl;
    cout<<"waiting-time, turn-around-time of processes arranged in asc order of their burst times"<<endl;
    // printing out all the results...
    cout<<"---------------------------------------------"<<endl;
    cout<<"\tP.ID \tA.T \tB.T\tW.T\tT.T"<<endl;
    cout<<"---------------------------------------------"<<endl;
    for(int k=0; k<n; k++)
    {
        cout<<"\t"<<proc[k]<<"\t"<<arival[k]<<"\t"<<burst[k]<<"\t"<<wait[k]<<"\t"<<turn[k]<<endl;
    }
    cout<<"---------------------------------------------"<<endl;
    cout<<"-> Average Waiting-time is ->"<<avg_wait<<" ms"<<endl;
    cout<<endl;
    cout<<"-> Average Turn-around-time is ->"<<avg_turn<<" ms"<<endl;
    cout<<endl;
    cout<<"-> Total-Time consumed is ->"<<tot_time<<" ms"<<endl;
    cout<<endl;
}