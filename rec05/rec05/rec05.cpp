#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>


using namespace std;




class Section {
private:
	string name;
	string day;
	int hour;

	vector<string> students;
	vector<vector<int>> grades;
public:
	Section(string _name, string _day, int _hour) {
		name = _name;
		day = _day;
		hour = _hour;
	}

	void set_name(string _name){
		name = _name;
	}


	void set_day(string _day){
		day = _day;
	}


	void set_hour(int _hour){
		hour = _hour;
	}


	void addStudent(string _name){
		students.push_back(_name);
		//also push back an array of 13 -1 ints
		vector<int> default_grades;
		for (int x = 0; x < 13; x++){
			default_grades.push_back(-1);
		}
		grades.push_back(default_grades);
	}


	string get_day(){
		return day;
	}

	int get_hour(){
		return hour;
	}

	string get_name(){
		return name;
	}


	string print(){
		return name + " " + day;
	}


	vector<string> get_students(){
		return students;
	}


	vector<int> get_grades(int index){
		return grades[index];
	}


	void reset(){
		students.clear();
		grades.clear();

	}


	void insert_grade(int _index, int _grade, int _week){
		grades[_index][_week] = _index;
	}


	void addStudent(string _name, int _grade, int _week){
		//find the index of the user with this name
		
	}



	void display(){
		string am_pm = "am";
		if (hour > 12){
			hour -= 12;
			am_pm = "pm";
		}
		cout << "Section: " + name + "; " + day + " " + to_string(hour) + am_pm << endl;
	}



};









class LabWorker {
private:
	string name;
	Section *section;
public:

	LabWorker(string _name){
		name = _name;
	}

	void set_name(string _name){
		name = _name;
	}


	string get_name(){
		return name;
	}


	void addSection(Section *_section){
		section = _section;
	}


	bool addGrade(string _name, int _grade, int _week){
		vector<string> students = section->get_students();
		for (int x = 0; x < section->get_students().size(); x++){
			string student_name = students[x];
			if (student_name == _name){
				section->insert_grade(x, _grade, _week);
				return true;
			}
		}
		//If code gets here, user is not in list
		return false;
	}




	void displayGrades(){

		//Student: John; Grades: -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
		vector<string> students = section->get_students();
		for (int y = 0; y < students.size(); y++){
			string student = students[y];
			vector<int> grades = section->get_grades(y);
			string grade_string = "";
			//convert int vector to string
			for (int i = 0; i < grades.size(); i++){
				grade_string += to_string(grades[i]) + " ";
			}

			cout << "Student: " + student + " Grades: " + grade_string << endl;
				
		}
	}
};







int main() {

	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");


	//cout << moe.to_string() << endl;

	//// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(&secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(&secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


	// setup is complete, now a real world scenario can be written in the code
	// [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

	// week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();


	system("pause");

} // main