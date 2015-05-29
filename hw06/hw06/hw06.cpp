#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <sstream>

#include "Noble.h"
#include "Warrior.h"



using namespace WarriorCraft;


std::ostream& operator<<(std::ostream& os, Noble& noble) {

	os << noble.get_name() + " has an army of " + std::to_string(noble.get_army_size()) << "\n";
	for (int x = 0; x < noble.get_army_size(); x++){
		/*Warrior warrior = (*army)[x];*/
		os << "    " + noble.get_army_index(x)->get_name() + ": " + std::to_string(noble.get_army_index(x)->get_strength()) << "\n";
	}

	return os;
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

	std::cout << jim << std::endl;
	std::cout << lance << std::endl;
	std::cout << art << std::endl;
	std::cout << linus << std::endl;
	std::cout << billie << std::endl;

	cheetah.runaway();
	std::cout << art << std::endl;

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);


	system("pause");
}


