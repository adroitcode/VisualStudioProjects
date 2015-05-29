#include <iostream>
#include <vector>


#include <fstream>
#include <string>
#include <vector>

#include <sstream>

#include "Rational.h"


namespace CS1124 {


	int greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}

	Rational::Rational(){
	}


	Rational::Rational(int _num, int _denom){
		num = _num;
		denom = _denom;
		normalize();
	}


	void Rational::normalize(){
		int gcd = greatestCommonDivisor(num, denom);


		num = num / gcd;
		denom = denom / gcd;
	}


	Rational::Rational(int number) {

		num = number;
		denom = 1;


	}


	

	//simplify fraction___
	//(n / GCD(n, d)) 
	//_______________	
	//(d / GCD(n, d))
	Rational Rational::operator+= (Rational& b)
	{
		//2/3 + 4/5

		int numerator = (num * b.get_denom()) + (b.get_num() * denom);
		int denominator = (denom * b.get_denom());



		int gcd = greatestCommonDivisor(numerator, denominator);
		


		Rational* new_r = new Rational(numerator / gcd, denominator / gcd);


		return *new_r;
	}

	void Rational::set_num(int _num){
		num = _num;
	}

	void Rational::set_denom(int _denom){
		denom = _denom;
	}

	Rational Rational::operator+ (Rational& b)
	{


		int numerator = (num * b.get_denom()) + (b.get_num() * denom);
		int denominator = (denom * b.get_denom());



		int gcd = greatestCommonDivisor(numerator, denominator);



		Rational* new_r = new Rational(numerator / gcd, denominator / gcd);


		return *new_r;
	}

	Rational Rational::operator++ ()
	{

		num += (num * denom);



		return *this;
	}

	Rational Rational::operator++ (int num)
	{

		num += (num * denom);
		


		return *this;
	}


	Rational Rational::operator-- ()
	{

		num -= (num * denom);



		return *this;
	}

	Rational Rational::operator-- (int _num)
	{

		num -= (_num * denom);



		return *this;
	}

	bool Rational::operator== (Rational& b)
	{

		if ((num / denom) == (b.get_num() / b.get_denom())){
			return true;
		}
		

		return false;
	}

	bool Rational::operator!= (Rational& b)
	{

		if ((num / denom) != (b.get_num() / b.get_denom())){
			return true;
		}


		return false;
	}

	






	void Rational::parse_input(const std::string &input){
		std::cout << "PARSING THIS INPUT: " << input << std::endl;

		std::size_t found = input.find("/");
		if (found != std::string::npos){
			num = std::stoi(input.substr(0, found));
			denom = std::stoi(input.substr(found + 1));

			//std::cout << "num: " << std::to_string(num) << " denom: " << std::to_string(denom) << std::endl;
			//std::cout << "num + denom = " << std::to_string(num + denom) << std::endl;



		}
		else{
			std::cout << "Invalid input." << std::endl;
		}
	}


	int Rational::get_num(){
		return num;
	}

	int Rational::get_denom(){
		return denom;
	}








}







