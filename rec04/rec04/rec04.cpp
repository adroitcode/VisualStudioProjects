#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>


using namespace std;


class PlainOldClass {
public:
	PlainOldClass() : x(-72) {}
	int getX() const { return x; }
	void setX(int x)  { this->x = x; } // HMMMM???
private:
	int x;
};

class Colour {
public:
	Colour(const string& name, unsigned r, unsigned g, unsigned b)
		: name(name), r(r), g(g), b(b) {}
	void display() const {
		cout << name << " (RBG: " << r << "," << g << "," << b << ")";
	}
private:
	string   name;    // what we call this color       
	unsigned r, g, b; // red/green/blue values for displaying  
};



class SpeakerSystem {
public:
	void vibrateSpeakerCones(unsigned signal) const {

		cout << "Playing: " << signal << "Hz sound..." << endl;
		cout << "Buzz, buzzy, buzzer, bzap!!!\n";
	}
};

class Amplifier {
public:
	Amplifier() : attachedSpeakers(NULL) {}
	void attachSpeakers(const SpeakerSystem& spkrs)
	{
		if (attachedSpeakers)
			cout << "already have speakers attached!\n";
		else
			attachedSpeakers = &spkrs;
	}
	void detachSpeakers()
	{
		attachedSpeakers = NULL;
	}
	// should there be an "error" message if not attached?
	void playMusic() const {
		if (attachedSpeakers)
			attachedSpeakers->vibrateSpeakerCones(440);
		else
			cout << "No speakers attached\n";
	}
private:
	const SpeakerSystem* attachedSpeakers;
};





class Person {
public:
	Person(const string& name) : name(name) {}
	void movesInWith(Person& newRoomate) {
		roomie = &newRoomate;        // now I have a new roomie            
		newRoomate.roomie = this;    // and now they do too       
	}
	string getName() const { return name; }
	// Don't need to use getName() below, just there for you to use in debugging.
	string getRoomiesName() const { return roomie->getName(); }
private:
	Person* roomie;
	string name;
};



vector<string> get_file_lines(ifstream &file){
	vector<string> file_lines;
	string str;

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
vector<string> split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string number;
	while (getline(ss, number, delim)) {
		elems.push_back(number);
	}
	return elems;
}



int main(){

	int x;
	x = 10;
	cout << "x = " << x << endl;

	int* p;     // it's very clear that the * is part of the type's name - the type is "pointer to int"
	////                            PREFERRED     
	//int *p;     // it looks the * is part of the variable name but the compiler reads it as above
	//int * p;    // it looks more like multiplication but the compiler again reads it as above
	////		       (probably NOT a good idea to use)
	//int* p1, p2, *p3;   // This is compileable code but's it's VERY unclear as the type of i.
	//// Since the * is part of the type's name, it's clear that p1 is an int*; and it's pretty clear that
	////  p3 is an int* but notice that it looks like p2 is also an int* - but it's not!
	////      (definitely NOT a good idea to mix int and int* definitions


	//*p = -2763;
	//cout << "p points to where " << *p << " is      stored\n";
	//cout << "*p now contains " << *p << endl;
	//cout << "x now contains " << x << endl;

	int y(13);
	//cout << "y contains " << y << endl;
	p = &y;
	//cout << "p now points to where " << *p << " is stored\n";
	//cout << "*p now contains " << *p << endl;
	*p = 980;
	cout << "p points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	cout << "y now contains " << y << endl;


	//int joe(24);
	//const int sal(19);
	//int*  pI;
	//  pI = &joe;  
	// *pI = 234;  
	//  pI = &sal;  
	// *pI = 7623;    

	//const int* pcI;
	//  pcI = &joe;  
	// *pcI = 234;  
	//  pcI = &sal;  
	// *pcI = 7623;    

	//int* const cpI;
	//int* const cpI(&joe);
	//int* const cpI(&sal);
	//  cpI = &joe;  
	// *cpI = 234;  
	//  cpI = &sal;  
	// *cpI = 7623;    

	//const int* cpcI;
	//const int* cpcI(&joe);
	//const int* cpcI(&sal);
	  //cpcI = &joe;  
	 //*cpcI = 234;  
	  //cpcI = &sal;  
	 //*cpcI = 7623;  


	//PlainOldClass poc;
	//PlainOldClass* ppoc(&poc);
	//cout << ppoc->getX() << endl;
	//ppoc->setX(2837);
	//cout << ppoc->getX() << endl;




	//vector<Complex*> compli;
	//Complex* tmpPCmplx;      // grab heap space for 3 Complex objects and "store" them
	//// in the vector. We are really storing the Complex objects
	//// we think of this as "storing" them
	//for (size_t ndx = 0; ndx < 3; ++ndx) {
	//	tmpPCmplx = new Complex;
	//	tmpPCmplx->real = ndx;
	//	tmpPCmplx->img = ndx;
	//	compli.push_back(tmpPCmplx);
	//}
	//// display them      
	//for (size_t ndx = 0; ndx < 3; ++ndx) {
	//	cout << compli[ndx]->real << endl;
	//	cout << compli[ndx]->img << endl;
	//}
	//// release them      
	//for (size_t ndx = 0; ndx < 3; ++ndx) {
	//	delete compli[ndx];
	//}
	//// clear the vector      
	//compli.clear();





	vector< Colour* > colours;
	string inputname;
	unsigned inputr, inputg, inputb;   // fill vector with colours from the file       
	// this could be from a file but we are using the keyboard for now       
	// (do you remember the keystrokes to indicate "end of file" at the keyboard?)    




	ifstream file;

	file.open("colors.txt");



	vector<string> file_lines = get_file_lines(file);


	for (int x = 0; x < file_lines.size(); x++){
		vector<string>line_parts = split(file_lines[x], ' ');
		colours.push_back(new Colour(line_parts[0], stoi(line_parts[1]), stoi(line_parts[2]), stoi(line_parts[3])));
	}

	//colours.push_back(new Colour("red", 1, 201, 255));
	//colours.push_back(new Colour("black", 255, 255, 255));

	// display all the colours in the vector:       
	for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
		colours[ndx]->display();
		cout << endl;
	}


	for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
		delete colours[ndx];
	}







	SpeakerSystem speaker_system;
	Amplifier amp;

	amp.attachSpeakers(speaker_system);

	amp.playMusic();



	// write code to model two people in this world       
	Person joeBob("Joe Bob"), billyJane("Billy Jane");
	// now model these two becoming roommates       
	joeBob.movesInWith(billyJane);
	// did this work out?       
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;




	system("pause");
}	