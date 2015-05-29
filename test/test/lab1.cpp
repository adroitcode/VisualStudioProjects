#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void show_file(ifstream &myReadFile){
	//print file line by line
	string line; 



	int a = 0;
	string previousLine = "";
	while (a<1) // To get you all the lines.
	{
		getline(myReadFile, line); // Saves the line in STRING.
		if (line != previousLine)
		{
			previousLine = line;
			cout << line << endl; // Prints our STRING.
		}

	}
	myReadFile.clear();
	myReadFile.seekg(0);
}



int count_words(ifstream &myReadFile){
	int word_count = 0;

	

	
	char output[100];
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			word_count++;
			myReadFile >> output;
			//cout << output;
			//cout << endl;
		}
	}
	

	myReadFile.clear();
	myReadFile.seekg(0);
	return word_count;
}


int main2() {
	ifstream myReadFile;


	myReadFile.open("text.txt");

	if (myReadFile){
		cout << count_words(myReadFile) << endl;

		show_file(myReadFile);
	}


	myReadFile.close();


	system("pause");
	return 0;
}