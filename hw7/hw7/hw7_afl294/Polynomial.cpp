#include <iostream>
#include <vector>


#include <fstream>
#include <string>
#include <vector>

#include <sstream>

#include "Polynomial.h"



Polynomial::Polynomial(){
	degree = 0;
	node = nullptr;

}

Polynomial::Polynomial(Polynomial& other) {
	node = other.get_node();


}


void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}


Polynomial::Polynomial(std::vector<int> ints){
	degree = -1;

	//4x^3 + x + 7 

	//head_ptr --> 7 --> 1 --> 0 --> 4
	//degree:  3
	for (size_t x = ints.size(); x-- > 0;){
		listInsertHead(ints[x], node);
		degree += 1;
	}

	//std:: cout << degree;

}

Node* Polynomial::get_node(){
	return node;
}


int Polynomial::get_degree(){
	return degree;
}
	
Polynomial::~Polynomial(){



}

double Polynomial::evaluate(int x){
	return 0;
}




Polynomial Polynomial::operator+ (Polynomial& b) {


	std::vector<int> sums;
	size_t loop_count = degree;
	Node* larger_node = node;
	Node* smaller_node = b.get_node();

	if (b.get_degree() > degree){
		loop_count = b.get_degree();
		larger_node = b.get_node();
		smaller_node = node;
	}

	Node* temp1 = larger_node;
	Node* temp2 = smaller_node;

	

	for (size_t x = 0; x < loop_count + 1; x++){
		int sum = 0;
		if (temp1){
			sum += temp1->data;
			temp1 = temp1->link;
		}

		if (temp2){
			sum += temp2->data;
			temp2 = temp2->link;
		}

		sums.push_back(sum);
	}

	std::reverse(sums.begin(), sums.end());


	Polynomial* new_r = new Polynomial(sums);


	return *new_r;
}

void Polynomial::operator+= (Polynomial& b)
{


	size_t loop_count = b.get_degree(); 
	Node* larger_node = node;
	Node* smaller_node = b.get_node();

	if (b.get_degree() > degree){
		loop_count = degree;
		larger_node = b.get_node();
		smaller_node = node;
	}

	node = larger_node;
	Node* temp = node;

	//loop thru the smaller node
	for (size_t x = 0; x < loop_count + 1; x++){
		listInsertHead(temp->data + smaller_node->data, node);
		temp = temp->link;
	}


}


bool Polynomial::operator== (Polynomial& b)
{

	if (degree == b.get_degree()){
		Node* temp1 = node;
		Node* temp2 = b.get_node();
		while (temp1){
			if (temp1->data != temp2->data){
				return false;
			}
		}

		return true;
	}
	else{
		return false;
	}

	
}

bool Polynomial::operator!= (Polynomial& b)
{

	if (degree != b.get_degree()){
		return true;
	}
	else{
		Node* temp1 = node;
		Node* temp2 = b.get_node();
		while (temp1){
			if (temp1->data != temp2->data){
				return true;
			}
		}

		return false;
	}

}






