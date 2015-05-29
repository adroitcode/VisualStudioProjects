#pragma once



#ifndef NOBLE_H
#define NOBLE_H


#include <algorithm> 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



namespace WarriorCraft {


	class Warrior;



	class Noble{

	protected:
		std::vector<Warrior *> army;
		std::string name;


	public:
		Noble();
		Noble(const std::string&);


		void set_name(std::string _name);


		std::string get_name();


		std::string print();


		int get_army_strength();

		int get_army_size();


		Warrior* get_army_index(int index);

		void hire(Warrior *warrior);

		void display();

		void fire(Warrior *warrior);

		void die();


		void battle(Noble noble);

	};








}


#endif











