#pragma once



#ifndef COURSE_H
#define COURSE_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>




namespace BrooklynPoly {

	class User;


	class Course {

		int id;
		std::string name;
		std::vector<User *> students;

	public:
		Course(const std::string &_name);

		std::string get_name();


		void add_student(User *student);



		void clear_students();
	};

}


#endif
	










