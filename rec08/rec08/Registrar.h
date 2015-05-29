#pragma once

#include <iostream>
#include <vector>

#include "Course.h"
#include "User.h"


#include <fstream>
#include <string>
#include <vector>

#include <sstream>



#ifndef REGISTRAR_H
#define REGISTRAR_H


namespace BrooklynPoly {
	class Registrar {

		std::vector<User *> students;
		std::vector<Course *> courses;


	public:
		Registrar();
		std::string printReport();
		void addCourse(const std::string &course_name);
		void addStudent(const std::string &student_name);
		int find_user_index_by_name(const std::string &user_name);
		int find_course_index_by_name(const std::string &course_name);

		void enrollStudentInCourse(std::string user_name, std::string course_name);
		void cancelCourse(const std::string &course_name);
		void purge();
	};

}


#endif





