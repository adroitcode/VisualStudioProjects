#include <iostream>
#include <vector>

#include "Noble.h"
#include "Warrior.h"


#include <fstream>
#include <string>
#include <vector>
#include <sstream>



namespace WarriorCraft {



	Noble::Noble(){

	}

	Noble::Noble(const std::string &_name){

		name = _name;
	}





	void Noble::set_name(std::string _name){
		name = _name;
	}


	std::string Noble::get_name(){
		return name;
	}


	std::string Noble::print(){
		return "";
	}


	int Noble::get_army_strength(){
		int army_strength = 0;
		for (int x = 0; x < army.size(); x++){
			army_strength += army[x]->get_strength();
		}
		return army_strength;
	}


	int Noble::get_army_size(){
		return army.size();
	}

	void Noble::hire(Warrior *warrior){
		warrior->add_noble(this);
		std::cout << "Added noble " + (this)->get_name() + " to a warrior" << std::endl;
		army.push_back(warrior);
	}




	Warrior* Noble::get_army_index(int index){
		return army[index];
	}


	void Noble::display(){
		std::cout << name + " has an army of " + std::to_string(army.size()) << std::endl;
		for (int x = 0; x < army.size(); x++){
			/*Warrior warrior = (*army)[x];*/
			std::cout << "    " + army[x]->get_name() + ": " + std::to_string(army[x]->get_strength()) << std::endl;
		}
	}

	void Noble::fire(Warrior* warrior){
		for (int x = 0; x < army.size(); x++){
			if (army[x]->get_name() == warrior->get_name()){
				std::cout << warrior->get_name() + ", you're fired! -- " + name << std::endl;
				army.erase(army.begin() + x);
				break;
			}
		}
	}

	void Noble::die(){
		for (int x = 0; x < army.size(); x++){
			army[x]->set_strength(0);
		}
	}


	void Noble::battle(Noble noble){
		std::cout << name + " battles " + noble.get_name() << std::endl;
		int this_army_stength = get_army_strength();
		int other_army_strength = noble.get_army_strength();

		if (this_army_stength == 0 && other_army_strength == 0){
			std::cout << "Oh, NO! The'yre both dead! Yuck!" << std::endl;
			return;
		}

		if (other_army_strength == 0){
			std::cout << "He's dead " + name << std::endl;
			return;
		}

		if (this_army_stength == other_army_strength){
			std::cout << "Mutual Anihalation: " + name + " and " + noble.get_name() + " die at each other's hands" << std::endl;
		}
		else if (this_army_stength > other_army_strength){
			std::cout << name + " defeats " + noble.get_name() << std::endl;
			noble.die();
		}
		else{
			std::cout << noble.get_name() + " defeats " + name << std::endl;
			die();
		}

	}


}





















