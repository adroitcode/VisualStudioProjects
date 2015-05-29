#include <iostream>
#include <vector>

#include "Warrior.h"


#include <fstream>
#include <string>
#include <vector>
#include <sstream>



namespace WarriorCraft {


	Warrior::Warrior(){

	}

	Warrior::Warrior(const std::string &_name, int _strength){
		name = _name;
		strength = _strength;
	}

	void Warrior::set_name(std::string _name){
		name = _name;
	}


	void Warrior::add_noble(Noble* _noble){
		noble = _noble;
	}


	void Warrior::runaway() {
		noble->fire(this);

		noble = nullptr;

		std::cout << "Warrior " + name + " ran away from his noble!" << std::endl;
	}


	std::string Warrior::get_name(){
		return name;
	}

	void Warrior::set_strength(int _strength){
		strength = _strength;
	}

	int Warrior::get_strength(){
		return strength;
	}


	std::string Warrior::print(){
		return "";
	}
	

	


}

