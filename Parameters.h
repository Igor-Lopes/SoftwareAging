/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes, Shuo Yan
** <This class will read all the parameters from the file: Parameters.dat
** September 21st, 2015
** -------------------------------------------------------------------------*/

#include <iostream> //Standard
#include <algorithm> //
#include <fstream> //Files manipulation
#include <cstring> //String manipulation

using namespace std;

class Parameters{

private:
string parameters[12];
int minSize;
int maxSize;
int minInterv;
int maxInterv;
int staticSize;
int staticTime;
bool isRunning;
bool isStatic;
	public: void readParameters(){ //Reads Parameters.dat and all its content
        	ifstream fin ("Parameters.dat");
        	string line;
        	int last_index = 0;
        	while(getline(fin, line)){
                	parameters[last_index] = line; //Stores all lines in this string array.
                	last_index++;
        	}
        	fin.close();
	}

	public: void setParameters(){ //Sets the values of the parameters
		string run = filterStr(parameters[0], "RUNNING= "); //Gets the value of isRunning.
		if(run.compare("true") == 0){
			isRunning = true;
		} else {
			isRunning = false;
		}
		string stat  = filterStr(parameters[5], "STATIC= ");//Gets the value of isStatic.
		 if(stat.compare("true") == 0){
                        isStatic = true;
                } else {
                        isStatic = false;
                }
                //String filtering and conversion of the values from string to integer
		minInterv = stoi( filterStr(parameters[8], "INTERV_MIN= "));
		maxInterv = stoi( filterStr(parameters[9], "INTERV_MAX= "));
		minSize = stoi( filterStr(parameters[10], "ALLOC_MIN= "));
		maxSize = stoi( filterStr(parameters[11], "ALLOC_MAX,= "));
		staticSize = stoi( filterStr(parameters[6], "ALLOC_STATIC,= "));
		staticTime = stoi( filterStr(parameters[7], "INTERV_STATIC,= "));
	}

	public: string filterStr(string str, const char* toRemove){ //Filters String to get values
		for(int i = 0; i < strlen(toRemove); i++){
			str.erase( remove(str.begin(), str.end(), toRemove[i] ), str.end() );
		}
		return str;
	}

	//Getters fro the values
	public: int getMinInterval(){ return minInterv; }

	public: int getMaxInterval(){ return maxInterv; }

	public: int getMinSize(){ return minSize; }

	public: int getMaxSize(){ return maxSize; }

	public: int getStaticSize(){ return staticSize; }

	public: int getStaticTime(){ return staticTime; }

	public: bool getStatus(){ return isRunning; }

	public: bool getStatic(){ return isStatic; }

	public: void debugValues(){ //Debug: Print the values of the variables read from the Parameters file.
		cout <<"Min Size:"<< getMinSize() <<endl;
		cout <<"Max Size:"<< getMaxSize() <<endl;
		cout <<"Min Interv:"<< getMinInterval() <<endl;
                cout <<"Max Interv:"<< getMaxInterval() <<endl;
		cout <<"Static Size:"<< getStaticSize() <<endl;
		cout <<"Static Time:"<< getStaticTime() <<endl;
	}

};

