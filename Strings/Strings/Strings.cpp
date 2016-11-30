#include <iostream>
#include <fstream>
#include <string>

using namespace std;

////////// PROTOTYPES ///////////

string getFileName();
bool openFile(string fileName);
void readFile(string fileName);

////////////////////////////////

//main function
int main()
{
	string fileName = getFileName();
	readFile(fileName);

	return 0;
}

//getFileName function
string getFileName()
{

	string fileName;
	cout << "What is the name of the file that you would like to open? ";
	cin >> fileName;

	return fileName;
}


//open file function
bool openFile(string fileName)
{
	ifstream fin(fileName);
	if (fin.fail())
	{
		cout << "The file specified was not located or there was an error opening it." << endl;
		return false;
	}
	else
		return true;
}

// readFile function
void readFile(string fileName)
{
	bool isOkay = false;
	if (openFile(fileName) == true)
	{
		isOkay = true;
		cout << "This is the content of " << fileName << ": \n" << endl;
	}
	string content;
	ifstream fin(fileName);
	getline(fin, content);
	while (isOkay == true)
	{
		cout << "\"" << content << "\"" << endl;
		isOkay = false;
	}

	fin.close();			//make sure that the file is closed

	return;

}
