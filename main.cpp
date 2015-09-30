/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes, Shuo Yan
** September 21st, 2015
** -------------------------------------------------------------------------*/

#include <iostream>
#include <unistd.h> //Library which has the sleep command.
#include <pthread.h> //The library used to manage posix threads.
#include <cstdlib>
//------------------Headers--------------------------------------------------
#include "Parameters.h"
#include "Memory.h"

using namespace std;


int getRndTime(int n2, int n1){ return rand()% n2 + n1; } //Gets reandom interval.

void  *thread(void *arg){ //Posix thread method that will allocate memory and simulate the aging phenomena.
        Parameters p;
        p.readParameters();
        p.setParameters();
        //Get the values from the Parameter class in Parameter.h
        int minSize = p.getMinSize();
        int maxSize = p.getMaxSize();
        int minInterv = p.getMinInterval();
        int maxInterv = p.getMaxInterval();
        int staticSize = p.getStaticSize();
        int staticTime = p.getStaticTime();
        bool isStatic = p.getStatic();
        bool isRunning = p.getStatus();
        Memory mem( minSize, maxSize, staticSize, isStatic );
        int seconds = 0;
        cout << "-------------------------- Sysstress: Running --------------------------"<<endl;
	while(isRunning){
                if(seconds == 0){
                        if(isStatic == true){ 
                                seconds = staticTime; //Frequency
                                mem.allocStatic();
                                cout << "Seconds:" << seconds<<endl;
                        } else {
                                seconds = getRndTime( maxInterv, minInterv );
                                cout << "Seconds:" << seconds<<endl;
                                mem.allocDynamic();
                        }
                } else { 
                        p.readParameters();
                        p.setParameters();
                        isRunning = p.getStatus();
                        sleep(1);
                        seconds--;
                }
        }
        cout << "-------------------------- Sysstress: Endend --------------------------"<<endl;
}

int main(){
        pthread_t threads[1]; //Number of threads to be run in parallell.
        int rc;
        for(int i = 0; i < 1; i++){
                rc = pthread_create(&threads[i],0,thread,NULL);//Creates and starts each thread.
                if(rc){
                        cout << "Error "<<endl;
                        exit(-1);
                }
        } 
//Exits
pthread_exit(NULL);
return 0;
}
