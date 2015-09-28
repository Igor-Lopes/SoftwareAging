/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes, Shuo Yan
** September 21st, 2015
** -------------------------------------------------------------------------*/

#include <ctime> //ctime function used with Random.
#include <cstdlib> //Random function.
#include <fstream> //Library used to read/write files.

using namespace std;

class File{

private:

int size_limit;
int file_lines;
	public: File(){
		srand(time(0)); //Sets the seed
		size_limit = 100;//Limit of the file: 100Kb.
		file_lines = 0;
	}

	public: int getFileSize(){ //Gets the current size of the file.
		FILE *pFile = NULL;
		int size;
		pFile = fopen ("test.dat","rb");
		fseek (pFile,0,SEEK_END); //Points to the end of the file.
		size = ftell (pFile); //Gets its size in bytes.
		fclose (pFile); //Closes the stream
		return size/1000; //Returns the size in Kbytes.
	}

	public: char getRand(){ //Method returns a random character.
        	const char alphabet[]=
        	"abcdefghijklmnopqrstuvwxyz"
        	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        	"0123456789";
        	int lenght = sizeof (alphabet) - 1;
        	return alphabet[rand() % lenght];
	}

	public: void writeFile(){  //Creates a file with random string content.
        	ofstream fout ("test.dat");
		int file_size = 0;
		while(file_size < size_limit){
			file_size = getFileSize();
			fout << getRand() << endl;
			file_lines++;
		}
        	fout.close();
	//	cout << file_lines << endl;
	}

	public: void getData(){ //Reads the file "data.dat" and puts all of its content on an dynamic string array.
        string *data = new string [file_lines];
        int index = 0;
        string line;
        ifstream openFile("test.dat");
        while(getline(openFile, line)){
                data[index] = line;
 		index++;
        }
	cout << index<<endl;
        openFile.close();
	}
};
