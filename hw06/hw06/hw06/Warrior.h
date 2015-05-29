#pragma once



#ifndef WARRIOR_H
#define WARRIOR_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Noble.h";




namespace WarriorCraft {


	class Warrior{

		protected:
			Noble* noble;
			std::string name;
			int strength;


		public:
			Warrior();
			Warrior(const std::string&, int);

			void set_name(std::string);

			void add_noble(Noble*);


			std::string get_name();

			void set_strength(int _strength);

			int get_strength();


			std::string print();


			void runaway();
	};


}




#endif