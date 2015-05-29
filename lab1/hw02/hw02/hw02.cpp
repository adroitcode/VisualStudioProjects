#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>


using namespace std;


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



class Weapon {
	public:
		Weapon();
		Weapon(string,int);
		int strength;
		string name;
		
		void set_strength(int _strength){
			strength = _strength;
		}

		void set_name(string _name){
			name = _name;
		}


		int get_strength(){
			return strength;
		}


		string get_name(){
			return name;
		}
};



Weapon::Weapon(string _name, int _strength){
	name = _name;
	strength = _strength;
}


class Warrior{

protected:
	string name;
	Weapon* weapon;

	
public:
	Warrior();
	Warrior(const string&);

	void set_name(string _name){
		name = _name;
	}


	string get_name(){
		return name;
	}

	string get_weapon_name(){
		return weapon->get_name();
	}
	


	void set_strength(int _strength){
		weapon->strength = _strength;
	}

	int get_strength(){
		return weapon->get_strength();
	}


	string print(){
		return "";
	}
};

Warrior::Warrior(const string &file_line){
	vector<string>line_parts = split(file_line, ' ');
	name = line_parts[1];

	weapon = new Weapon(line_parts[2], stoi(line_parts[3]));


	//weapon.set_name(line_parts[2]);
	//weapon.set_strength(stoi(line_parts[3]));
}





void show_status(vector<Warrior> &warriors){
	cout << "There are: " + to_string(warriors.size()) + " warriors" << endl;

	for (int x = 0; x < warriors.size(); x++){
		cout << "Warrior: " + warriors[x].get_name() + ", weapon: " + warriors[x].get_weapon_name() + " strength: " + to_string(warriors[x].get_strength()) << endl;
	}
}




//Returns the index in the list of warriors 
//if warrior with name is found,
//otherwise returns -1
int find_warrior_index_by_name(vector<Warrior> &warriors, const string &warrior_name){
	for (int x = 0; x < warriors.size(); x++){
		if (warriors[x].get_name() == warrior_name){
			return x;
		}
	}

	//If code gets here, warrior with name was not found
	return -1;
}



void battle(vector<Warrior> &warriors, const string &file_line){
	vector<string>line_parts = split(file_line, ' ');

	string first_warrior_name = line_parts[1];
	string second_warrior_name = line_parts[2];


	int first_warrior_index = find_warrior_index_by_name(warriors, first_warrior_name);
	int second_warrior_index = find_warrior_index_by_name(warriors, second_warrior_name);

	if (first_warrior_index == -1){
		cout << "Warrior with name " + first_warrior_name + " not found" << endl;
	}

	if (second_warrior_index == -1){
		cout << "Warrior with name " + second_warrior_name + " not found" << endl;
	}


	cout << first_warrior_name + " battles " + second_warrior_name << endl;

	if (warriors[first_warrior_index].get_strength() == warriors[second_warrior_index].get_strength()){
		cout << "Mutual Annihilation: " + first_warrior_name + " and " + second_warrior_name + " die at each other's hands" << endl;
		warriors[first_warrior_index].set_strength(0);
		warriors[second_warrior_index].set_strength(0);
	}
	else if (warriors[first_warrior_index].get_strength() > warriors[second_warrior_index].get_strength()){
		cout << first_warrior_name + " defeats " + second_warrior_name << endl;
		if (warriors[first_warrior_index].get_strength() > warriors[second_warrior_index].get_strength()){
			warriors[second_warrior_index].set_strength(0);
		}
		else{
			warriors[second_warrior_index].set_strength(warriors[second_warrior_index].get_strength() - warriors[first_warrior_index].get_strength());
		}
	}
	else {
		cout << second_warrior_name + " defeats " + first_warrior_name << endl;
		if (warriors[second_warrior_index].get_strength() > warriors[first_warrior_index].get_strength()){
			warriors[first_warrior_index].set_strength(0);
		}
		else{
			warriors[first_warrior_index].set_strength(warriors[first_warrior_index].get_strength() - warriors[second_warrior_index].get_strength());
		}
	}

}


int main(){

	vector<Warrior> warriors;


	ifstream file;

	file.open("warriors.txt");

	vector<string> file_lines = get_file_lines(file);

	//Go through each line in the file and 
	//perform the proper action
	for (int x = 0; x < file_lines.size(); x++){
		string file_line = file_lines[x];
		if (file_line.find("Warrior") != string::npos){
			Warrior new_warrior(file_line);
			warriors.push_back(new_warrior);
		}
		else if (file_line.find("Status") != string::npos){
			show_status(warriors);
		}
		else if (file_line.find("Battle") != string::npos){
			battle(warriors, file_line);
		}
		else{
			cout << "Command not recognized" << endl;
		}


	}



	file.close();

	system("pause");
}

