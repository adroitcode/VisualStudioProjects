#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <cstdlib> // To allow NULL if no other includes
#include <bitset>


struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};


//Write a function to display an integer in binary. Trace its execution in the debugger. Show the lab worker your code and let them watch your trace.
//Write a function to create and return a new list that is the sum of the values in the the two lists passed in.You may assume that the two lists are the same length.Show the lab worker your code and let them watch your trace.
//Write a function to return the maximum of the values in a binary tree.Use the attached code.Note, there is a constant INT_MIN defined in the include file <climits> that is the value of the smallest possible int.This could make your life easier.
//Write a function to return the int "sum" of the characters in a c - string.[see below for c - string issues] Show the lab worker your code and let them watch your trace.
//Implement the binary search algorithm for an array of characters.Trace through the execution of the function on an array of 14 or more characters.[Remember that the array must be sorted for this search algorithm to work.] Experiment with using different targets that will cause the function to search through different portions of the array, including not being found - at the front, at the back, in the middle and so on.Show the lab worker your code.They will ask you to predict the output of your program(without running it!).They will then watch you trace your code in the debugger and will check your prediction.
//Trace the execution of the following function with various inputs.Show the lab worker your code.They will ask you to predict the output of your program(without running it!).They will then watch you trace your code in the debugger and will check your prediction.
//void f(int n) {
//	if (n > 1) {
//		cout << 'a';
//		f(n / 2);
//		cout << 'b';
//		f(n / 2);
//	}
//	cout << 'c';
//}



Node* sum_nodes(Node* node_1, Node* node_2){
	Node* new_node = new Node();
	new_node->data = node_1->data + node_2->data;

	if (node_1->link){
		Node* node_1_next = node_1->link;
		Node* node_2_next = node_2->link;

		new_node->link = sum_nodes(node_1_next, node_2_next);
		return new_node;
	}
	else{
		return new_node;
	}
}




void print_node(Node*& root){
	std::cout << "Printing linked node list" << std::endl;
	Node* this_node;
	this_node = root;
	if (this_node){
		while (this_node){
			std::cout << "Node(" + std::to_string(this_node->data) + ") ";
			this_node = this_node->link;
		}
	}
	else{
		std::cout << "Node is null" << std::endl;
	}


	std::cout << std::endl;
}




void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}






void int_to_binary(int n)
{
	if (n / 2 != 0) {
		int_to_binary(n / 2);
	}
	std::cout << std::to_string(n % 2);
}



#include <iostream>
using namespace std;

struct TNode {
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr) : data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};


int largest(int int_1, int int_2){
	if (int_1 > int_2){
		return int_1;
	}
	else{
		return int_2;
	}
}

int max(TNode* root) {
	if (root == NULL){
		return -1;
	}

	int left = max(root->left);
	int right = max(root->right);
	if (root->data > left && root->data > right){
		return root->data;
	}
	else{
		return largest(left, right);
	}
}




//char a('A'), b;
//
//// a contains 'A' whose ASCII value is 65
//cout << "a contains '" << a
//<< "' whose ASCII value is " << int(a) << endl;  // note the cast to int on this line
//
//b = a + 1;
//
//// b contains 'B' whose ASCII value is 66
//cout << "b contains '" << b
//<< "' whose ASCII value is " << int(b) << endl;  // note the cast to int on this line
//
//char c('a' - 17 + '\n'); // not sure what number will be stored or what character it represents but let's see
//cout << "b contains '" << b
//<< "' whose ASCII value is " << int(b) << endl;  // note the cast to int on this line

int sum_chars(string s){
	int sum = 0;
	for (int i = 0; i < s.length(); i++){
		sum += s[i];
	}
	return sum;
}




int binary_search(char c_string[], char value_to_find, int array_size) {
	int low = 0, high = array_size - 1, midpoint = 0;

	while (low <= high)
	{
		midpoint = low + (high - low) / 2;

		// check to see if value is equal to item in array
		if (value_to_find == c_string[midpoint])
		{
			return midpoint;
		}
		else if (value_to_find < c_string[midpoint])
			high = midpoint - 1;
		else
			low = midpoint + 1;
	}

	// item was not found
	return -1;
}


void func(int n) {


	if (n > 1) {
		cout << 'a';
		func(n / 2);
		cout << 'b';
		func(n / 2);
	}
	cout << 'c';
}

int main() { 
	



	std::cout << "Int to binary" << std::endl;
	int_to_binary(50);
	std::cout << std::endl;




	Node* sum_node = new Node();
	Node* node_1 = new Node();
	Node* node_2 = new Node();

	for (size_t x = 0; x <= 7; x++){
		listInsertHead(x, node_1);
		listInsertHead(x, node_2);
	}
	//print_node(node_1);
	//print_node(node_2);
	
	sum_node = sum_nodes(node_1, node_2);
	print_node(sum_node);



	std::cout << "MAX OF TNODES" << std::endl;
	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl;





	std::cout << "Sum chars" << std::endl;
	std::cout << sum_chars("lol") << std::endl;



	
	char c_string[6] = "oxzxo";

	std::cout << "Binary search" << std::endl;

	std::cout << binary_search(c_string, 'x', 6) << std::endl;


	std::cout << "CALLING F() FROM #6" << std::endl;
	func(10);

	std::cout << std::endl;


	system("pause");
}