/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes, Shuo Yan
** September 21st, 2015
** -------------------------------------------------------------------------*/

#include <iostream>
#include <unistd.h> //Library which has the sleep command.
#include <pthread.h> //The library used to manage posix threads.
#include "Files.h"

using namespace std;

void  *thread(void *arg){ //Posix method thread which will allocate memory and simulate the aging phenomena.
        File files; //Instance of the class Files, since in C++ threads like this cannot be inside of a class.
        int seconds = 0;
        files.writeFile();
        while(true){
                if(seconds == 0){
                        seconds = 10; //Frequency
                        files.getData();
                        cout << "Data added to memory" <<endl;
                }else{
                        sleep(1);
                        seconds--;
                }
        }
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
