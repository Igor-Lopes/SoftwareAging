/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes, Shuo Yan
** September 21st, 2015
** -------------------------------------------------------------------------*/

#include <iostream>
#include <ctime> //ctime function used with Random.
#include <cstdlib> //Random function.
#include <fstream> //Library used to read/write files.
#include <unistd.h> //Library which has the sleep command.
#include <pthread.h> //The library used to manage posix threads.

using namespace std;


class Aging{

private:
int lines; //Number of lines of the file and number of characters.

public: Aging(){
lines = 100; //Set the number of lines.
}

public: char getRand(){ //Method returns a random character.
        const char alphabet[]=
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";
        int lenght = sizeof (alphabet) - 1;
        return alphabet[rand() % lenght];
}

public: void setData(){  //Creates a file with random string content.
        ofstream out ("data.dat");
        for(int i = 0; i < lines ; i++){
                out << getRand()<<endl;
        }
        out.close();
}

public: void getData(){ //Reads the file "data.dat" and puts all of its content on an dynamic string array.
        string *data = new string [lines];
        int index = 0;
        string line;
        ifstream openFile("data.dat");
        while(getline(openFile, line)){
                data[index] = line;
 index++;
        }
        openFile.close();
}

};


void  *thread(void *arg){ //Posix method thread which will allocate memory and simulate the aging phenomena.
        Aging aging; //Instance of the class Aging, since in C++ threads like this cannot be inside of a class.
        int seconds = 0;
        while(true){
                if(seconds == 0){
                        seconds = 10; //Frequency
                        srand(time(0));
                        aging.setData();
                        aging.getData();
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
