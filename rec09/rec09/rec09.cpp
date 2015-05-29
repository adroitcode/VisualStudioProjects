/*
Recitation 09
CS1124

Focus: Copy Control.  Uses dynamic array of pointers.
*/



#include <string>
#include <iostream>

#include <algorithm> 
using namespace std;

class Position {
	public:
		Position(const string& aTitle, double aSalary)
			: title(aTitle), salary(aSalary) {}
		string getTitle() const { return title; }
		double getSalary() const { return salary; }
		void changeSalaryTo(double d) { salary = d; }
	private:
		string title;
		double salary;
};

class Entry {
	public:
		Entry(const string& aName, unsigned aRoom, unsigned aPhone,
			Position& aPosition)
			: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
		}
		friend ostream& operator<<(ostream& os, Entry& e) {
			os << e.name << ' ' << e.room << ' ' << e.phone;
			return os;
		} // operato<<

		string get_name(){
			return name;
		}

		unsigned get_phone(){
			return phone;
		}

		unsigned get_room(){
			return room;
		}

		Position* get_position(){
			return pos;
		}
	private:
		string name;
		unsigned room;
		unsigned phone;
		Position* pos;
};

class Directory {
	public:
		Directory()
			: capacity(3), size(0), entries(new Entry*[2])
		{
			// Should we do this?  What do you think?
			for (size_t i = 0; i < capacity; i++) {
				entries[i] = nullptr;
			} // for
		} // Directory()



		///** Copy constructor */
		Directory(Directory& other) {
		
			cout << "COPY CONSTRUCTOR" << endl;
			size = other.size;
			capacity = other.capacity;
			entries = new Entry*[capacity];



			//init some new spaces for our entries
			for (size_t i = 0; i < capacity; i++) {
				entries[i] = nullptr;
			}

			//loop through the entries in this directory
			for (size_t x = 0; x < size; x++){
				Entry* other_entry = other.get_entry(x);
				//Create a deep copy
				Entry* new_entry = new Entry(other_entry->get_name(), other_entry->get_room(), other_entry->get_phone(), *other_entry->get_position());

				entries[x] = new_entry;
			}


		}

		/** Copy assignment operator */
		Directory& operator= (Directory& other)
		{
			cout << "=======================" << endl;


			Directory* temp_directory = new Directory(other); // re-use copy-constructor
			int x = 0;
			int y = 1;


			size = temp_directory->get_size();
			capacity = temp_directory->get_capacity();
			entries = temp_directory->get_entries();
			

			return *this;
		}


		/** Destructor */
		~Directory() {


			for (size_t i = 0; i < size; ++i)
			{
				delete entries[i];
			}

			delete [] entries;
		}


		//returns phone number when given key: dict["Alex Lopez"] -> 1112223333
		//returns null if there was no match
		unsigned operator[](const string &name) { 
			for (size_t x = 0; x < size; x++){
				Entry* entry = entries[x];

				if (entry->get_name() == name){
					return entry->get_phone();
				}
			}

			return NULL;
		}



		size_t get_capacity(){
			return capacity;
		}

		size_t get_size(){
			return size;
		}

		void add(const string& name, unsigned room, unsigned ph, Position& pos) {
			if (size >= capacity)	{
				
				// something is missing!!!  Add it!
				entries = new Entry*[capacity *= 2];

				// something is missing!!!  Add it!

			}
			Entry* new_entry = new Entry(name, room, ph, pos);
			entries[size] = new_entry;

			cout << "adding new entry: " << endl;
			cout << *new_entry << endl;

			++size;
		} // add


		Entry* get_entry(int x){
			return entries[x];
		}

		Entry** get_entries(){
			return entries;
		}


		friend ostream& operator<<(ostream& os, Directory& dt)
		{
			cout << "Printing directory:  " << endl;
			for (size_t x = 0; x < dt.get_size(); x++){
				os << *dt.get_entry(x) << endl;
			}
			return os;
		}


	private:
		Entry** entries;
		size_t size;
		size_t capacity;
};







void doNothing(Directory dir) { 
	cout << dir << endl; 
}

int main() {

	// Model as if there are these four kinds 
	// of position in the problem:
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	cout << d << endl;


	Directory d2 = d;	// What function is being used??

	cout << "D1[" + to_string(d.get_size()) + "]" << endl;
	cout << d << endl;

	cout << "D2[" + to_string(d2.get_size())  + "]" << endl;
	cout << d2 << endl;

	cout << "d2 size: " << to_string(d2.get_size()) << endl;

	d2.add("Gallagher", 111, 2222, techie);

	

	d2.add("Carmack", 314, 1592, peon);


	cout << "D2[" + to_string(d2.get_size()) + "]" << endl;
	cout << d2 << endl;

	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;

	
	cout << "D2: " << endl;
	cout << d2;


	cout << "D3: " << endl;
	cout << d3;

	cout << "Getting Gallaghers phone number with [] operator: " << endl;
	cout << to_string(d2["Gallagher"]) << endl;




	system("pause");

} // main
