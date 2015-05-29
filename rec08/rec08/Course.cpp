#include <iostream>
#include <vector>

#include "Course.h"
#include "User.h"

#include <fstream>
#include <string>
#include <vector>
#include <sstream>



namespace BrooklynPoly {

	Course::Course(const std::string &_name){
		id = 1;
		name = _name;
	}


	std::string Course::get_name(){
		return name;
	}


	void Course::add_student(User *student){
		students.push_back(student);
	}



	void Course::clear_students(){
		students.clear();
	}


}






