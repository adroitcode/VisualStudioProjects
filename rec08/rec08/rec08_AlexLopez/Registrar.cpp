#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>


#include "Registrar.h"



using namespace std;


#include "Course.h"
#include "User.h"



int course_id = 1;
int user_id = 1;

namespace BrooklynPoly {


	Registrar::Registrar(){
	}

		std::string Registrar::printReport(){
			string return_string = "";
			return_string += "Students: ";
			if (students.size() > 0){
				for (size_t x = 0; x < students.size(); x++){
					return_string = students[x]->get_name() + ", ";
				}
				return_string += " - ";
			}
			else{
				return_string += "None. ";
			}
			
			return_string += "Courses: "; 
			if (courses.size() > 0){
				for (size_t i = 0; i < courses.size(); i++){
					return_string += courses[i]->get_name() + ", ";
				}
				return_string += ". ";
			}
			else{
				return_string += "None. ";
			}
			

			return return_string;
		}


		void Registrar::addCourse(const std::string &course_name){
			Course* course = new Course(course_name);
			courses.push_back(course);
		}


		void Registrar::addStudent(const std::string &student_name){
			User* student = new User(student_name);
			students.push_back(student);
		}


		int Registrar::find_user_index_by_name(const std::string &user_name){
			for (size_t x = 0; x < students.size(); x++){
				if (students[x]->get_name() == user_name){
					return x;
				}
			}

			return -1;
		}


		int Registrar::find_course_index_by_name(const std::string &course_name){
			for (size_t x = 0; x < courses.size(); x++){
				if (courses[x]->get_name() == course_name){
					return x;
				}
			}

			return -1;
		}



		void Registrar::enrollStudentInCourse(std::string user_name, std::string course_name){
			int user_index = find_user_index_by_name(user_name);
			int course_index = find_course_index_by_name(course_name);

			
			if (user_index > -1 && course_index > -1){
				User* user = students[user_index];
				Course* course = courses[course_index];

				course->add_student(user);
				user->add_course(course);
			}
			else{
				std::cout << "could not find user or course: " + user_name + ", " + course_name << std::endl;
			}

		}



		void Registrar::cancelCourse(const std::string &course_name){
			int course_index = find_course_index_by_name(course_name);

			if (course_index > -1){
				Course* course = courses[course_index];

				//Remove all references to user in course vector
				course->clear_students();

				courses.erase(courses.begin() + course_index);
			}



		}



		void Registrar::purge(){
			//clear students and courses
			for (size_t x = 0; x < students.size(); x++){
				delete students[x];
			}
			students.clear();


			for (size_t x = 0; x < courses.size(); x++){
				delete courses[x];
			}
			courses.clear();



		}


}


