#include <iostream>
#include <vector>


#include <fstream>
#include <string>
#include <vector>

#include <sstream>

#include "User.h"
#include "Course.h"


namespace BrooklynPoly {


	int user_id = 1;

	User::User(const std::string &_name){
		id = user_id;
		name = _name;
		user_id++;
	}
	std::string User::get_name(){
		return name;
	}

	void User::add_course(Course *course){
		courses.push_back(course);
	}

}







