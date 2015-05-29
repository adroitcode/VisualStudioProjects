#pragma once


#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};




//4x^3 + x + 7 

//head_ptr --> 7 --> 1 --> 0 --> 4
//degree:  3

class Polynomial {

	Node* node;
	int degree;


	public:
		Polynomial();
		Polynomial(Polynomial& b);
		Polynomial(std::vector<int>);
		~Polynomial();


		// Overload += operator to add two Box objects.
		Polynomial operator+(Polynomial& b);
		Polynomial& operator=(Polynomial&);
		void operator+=(Polynomial& b);


		bool operator==(Polynomial& b);
		bool operator!=(Polynomial& b);

		double evaluate(int);

		Node* get_node();
		int get_degree();


};











#endif
