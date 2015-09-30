/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes, Shuo Yan
** September 21st, 2015
** -------------------------------------------------------------------------*/

#include <ctime> //ctime function used with Random.
#include <cstdlib> //Random function.

using namespace std;

class Memory{

private:
int minSize;
int maxSize;
int staticSize;
bool isStatic;

	public: Memory(int min, int max, int statSize, bool isStat){
		srand(time(0)); //Sets the seed
		minSize = min;
		maxSize = max;
		staticSize = statSize;
		isStatic = isStat;
	}

	public: int getSize(){ return rand() % 1024 + 1; }

	public: char getChar(){
		const char alphabet[]=
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "0123456789";
                int lenght = sizeof (alphabet) - 1;

        return alphabet[rand() % lenght];
	}

	public: void allocDynamic(){
		int size = getSize() * 1000;
		char *pchar;
		pchar = (char*) malloc (size);
		for(int i = 0; i < size; i++){
			pchar[i] = getChar();
		}
		cout << "Memory Allocated: " << size << "bytes" << endl;
	}

	public: void allocStatic(){
		int size = staticSize * 1000;
                char *pchar;
		pchar = (char*) malloc (size);
                for(int i = 0; i < size; i++){
                        pchar[i] = getChar();
                }
		cout << "Memory Allocated: " << size << "bytes" << endl;
	}

	 public: void debugValues(){ //Print the values of the variables passed to this class.
                cout <<"Min Size:"<< minSize <<endl;
                cout <<"Max Size:"<< maxSize <<endl;
                cout <<"Static Size:"<< staticSize <<endl;
		if(isStatic){
			cout << "Static: true" <<endl;
		} else {
			cout << "Static: false" <<endl;
		}
        }
};
