#pragma once


#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


namespace CS1124 {


	class Rational {

		int num;
		int denom;


		public:
			Rational();
			Rational(int);
			Rational(int, int);

			void parse_input(const std::string &input);

			int get_num();
			int get_denom();

			void set_num(int);
			void set_denom(int);

			// Overload += operator to add two Box objects.
			Rational operator+=(Rational& b);
			Rational operator+(Rational& b);
			Rational operator++(int);
			Rational operator++();

			Rational operator--(int);
			Rational operator--();
			bool operator==(Rational& b);
			bool operator!=(Rational& b);
			void normalize();






	};



}


#endif
