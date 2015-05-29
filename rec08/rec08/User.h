#pragma once


#ifndef USER_H
#define USER_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


namespace BrooklynPoly {
	class Course;

	class User {

		int id;
		std::string name;
		std::vector<Course *> courses;


	public:
		User(const std::string &_name);
		std::string get_name();

		void add_course(Course *course);
	};



}

#endif



























