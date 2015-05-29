#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>


using namespace std;





class Warrior{

protected:
	string name;
	int strength;


public:
	Warrior();
	Warrior(const string&, int);

	void set_name(string _name){
		name = _name;
	}


	string get_name(){
		return name;
	}

	void set_strength(int _strength){
		strength = _strength;
	}

	int get_strength(){
		return strength;
	}


	string print(){
		return "";
	}
};

Warrior::Warrior(const string &_name, int _strength){
	name = _name;
	strength = _strength;
}





class Noble{

protected:
	vector<Warrior *> army;
	string name;


public:
	Noble();
	Noble(const string&);

	void set_name(string _name){
		name = _name;
	}


	string get_name(){
		return name;
	}


	string print(){
		return "";
	}


	int get_army_strength(){
		int army_strength = 0;
		for (int x = 0; x < army.size(); x++){
			army_strength += army[x]->get_strength();
		}
		return army_strength;
	}

	void hire(Warrior *warrior){
		army.push_back(warrior);
	}

	void display(){
		cout << name + " has an army of " + to_string(army.size()) << endl;
		for (int x = 0; x < army.size(); x++){
			/*Warrior warrior = (*army)[x];*/
			cout << "    " + army[x]->get_name() + ": " + to_string(army[x]->get_strength()) << endl;
		}
	}

	void fire(Warrior warrior){
		for (int x = 0; x < army.size(); x++){
			if (army[x]->get_name() == warrior.get_name()){
				cout << warrior.get_name() + ", you're fired! -- " + name << endl;
				army.erase(army.begin() + x);
				break;
			}
		}
	}

	void die(){
		for (int x = 0; x < army.size(); x++){
			army[x]->set_strength(0);
		}
	}


	void battle(Noble noble){
		cout << name + " battles " + noble.get_name() << endl;
		int this_army_stength = get_army_strength();
		int other_army_strength = noble.get_army_strength();

		if (this_army_stength == 0 && other_army_strength == 0){
			cout << "Oh, NO! The'yre both dead! Yuck!" << endl;
			return;
		}

		if (other_army_strength == 0){
			cout << "He's dead " + name << endl;
			return;
		}

		if (this_army_stength == other_army_strength){
			cout << "Mutual Anihalation: " + name + " and " + noble.get_name() + " die at each other's hands" << endl;
		}
		else if (this_army_stength > other_army_strength){
			cout << name + " defeats " + noble.get_name() << endl;
			noble.die();
		}
		else{
			cout << noble.get_name() + " defeats " + name << endl;
			die();
		}

	}

};

Noble::Noble(const string &_name){

	name = _name;
}



int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(&nimoy);
	lance.hire(&theGovernator);
	art.hire(&wizard);
	lance.hire(&dylan);
	linus.hire(&lawless);
	billie.hire(&mrGreen);
	art.hire(&cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);



	system("pause");
}


