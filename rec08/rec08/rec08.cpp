#include "Registrar.h"
#include <iostream>



#include <vector>

#include <fstream>
#include <string>
#include <vector>

#include <sstream>



using namespace BrooklynPoly;



std::vector<std::string> get_file_lines(std::ifstream &file){
	std::vector<std::string> file_lines;
	std::string str;

	while (getline(file, str)){
		file_lines.push_back(str);
	}

	//move the file pointer back to start of file
	file.clear();
	file.seekg(0);

	return file_lines;
}


//Splits string at delimeter and returns 
//vector<string> of each part
std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string number;
	while (getline(ss, number, delim)) {
		elems.push_back(number);
	}
	return elems;
}


int main() {



	Registrar registrar;


	std::ifstream file;

	file.open("transactions.txt");


		

	std::vector<std::string> file_lines = get_file_lines(file);
	file.close();


	for (size_t x = 0; x < file_lines.size(); x++){
		std::string file_line = file_lines[x];
		std::vector<std::string> file_line_parts = split(file_line, ' ');

		if (file_line_parts[0] == "AddCourse"){
			std::cout << "AddCourse " + file_line_parts[1] + " \n";
			registrar.addCourse(file_line_parts[1]);
			std::cout << std::endl;
		}
		else if (file_line_parts[0] == "PrintReport"){
			std::cout << "Printing Report";
			std::cout << registrar.printReport();
			std::cout << std::endl;
		}
		else if (file_line_parts[0] == "EnrollStudentInCourse"){
			std::cout << "EnrollStudentInCourse " + file_line_parts[1] + "  " + file_line_parts[2] + " \n";
			registrar.enrollStudentInCourse(file_line_parts[1], file_line_parts[2]);
			std::cout << std::endl;
		}
		else if (file_line_parts[0] == "CancelCourse"){
			std::cout << "CancelCourse " + file_line_parts[1] + " \n";
			registrar.cancelCourse(file_line_parts[1]);
			std::cout << std::endl;
		}
		else if (file_line_parts[0] == "Purge"){
			std::cout << "Purge\n";
			registrar.purge();
			std::cout << std::endl;
		}
	}




	system("pause");
}






