/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes, Shuo Yan
** This class will be resposible for memory allocation and reproducing software aging.
** September 21st, 2015
** -------------------------------------------------------------------------*/

#include <ctime> //ctime function used with Random.
#include <cstdlib> //Random function.

using namespace std;

class Memory{

private:
int minSize; //Min size to be allocated if not static stressing.
int maxSize; //Max size to be allocated if not static stressing.
int staticSize; ////Size to be allocated if static stressing.
bool isStatic; //Check if static testing. [To be removed in next commit, unnecessary]

	public: Memory(int min, int max, int statSize, bool isStat){ //Constructor
		srand(time(0)); //Sets the seed
		//Sets values
		minSize = min;
		maxSize = max;
		staticSize = statSize;
		isStatic = isStat;
	}

	public: int getSize(){ return rand() % 1024 + 1; } //Gets random size in interval

	public: char getChar(){ //Gets random character
		const char alphabet[]=
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "0123456789";
                int lenght = sizeof (alphabet) - 1;

        return alphabet[rand() % lenght];
	}

	public: void allocDynamic(){ //Dynamic allocation (Random allocation of block memory of random size)
		int size = getSize() * 1000; //Kbytes to Bytes.
		char *pchar; //Pointer.
		pchar = (char*) malloc (size); //Request memory to heap.
		for(int i = 0; i < size; i++){ //Gives pointer values so it will stay stuck in memory.
			pchar[i] = getChar();
		}
		cout << "Memory Allocated: " << size << "bytes" << endl;
	}

	public: void allocStatic(){ //Static allocation (Static memory allocation)
		int size = staticSize * 1000; //Kbytes to Bytes
                char *pchar; //Pointer
		pchar = (char*) malloc (size); //Request memory to heap.
                for(int i = 0; i < size; i++){
                        pchar[i] = getChar(); //Gives pointer values so it will stay stuck in memory.
                }
		cout << "Memory Allocated: " << size << "bytes" << endl;
	}
	//[To be removed] Print the values of the variables passed to this class.
	 public: void debugValues(){ 
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
