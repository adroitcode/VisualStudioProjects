
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <cstdlib> // To allow NULL if no other includes

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}


//inserts other list into list at certain pointer
void splice_in(Node*& root, Node*& splice_list, Node*& node_pointer){
	if (root){
		//Loop through root until we hit a 0 pointer,
		//meaning the end of the list
		//and look for the node_pointer

		Node* this_node_pointer;
		//Create another node pointer
		//to save position in loop
		//start at first node, root
		this_node_pointer = root;

		while (this_node_pointer){
			
			if (this_node_pointer->data == root->data){
				//Increment this_node_pointer one up, even if its null
				this_node_pointer = this_node_pointer->link;


				//After this node is where we want to insert the splice_list
				//Save to where this node pointer is currently pointing
				Node* insertion_point_node_link = this_node_pointer->link;
				

				//loop through  splice list until we hit end of list
				Node* this_splice_node;
				this_splice_node = splice_list;

				while (this_splice_node){
					//Make the last node link to this splice node
					this_node_pointer->link = this_splice_node;


					//Increment the last node pointer
					this_node_pointer = this_node_pointer->link;
					//Increment the splice node
					this_splice_node = this_splice_node->link;

				}


				//Make the last this_node_pointer point to the
				//insertion_point_node_link, even if it was null originally
				this_node_pointer->link = insertion_point_node_link;
			}

			//Update the current node pointer
			this_node_pointer = this_node_pointer->link;
		}
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



std::bitset<8> int_to_binary(char a){
	return (std::bitset<8>) a;
}



Node* search_sub_list(Node*& root, Node*& sub_node_list){
	Node *this_node_pointer = root;
	while (this_node_pointer){
		if (this_node_pointer->data == sub_node_list->data){
			//The first data matches, so lets loop through the rest of the sub_node_list
			//and compare next values in root
			Node* sub_node = sub_node_list;
			Node* temp_root_node_pointer = this_node_pointer;
			bool found = true;


			while (sub_node){
				//make sure the temp pointer isnt null
				if (!temp_root_node_pointer){
					//We've reached end of list before finishing looping 
					//through sub_list, so return NULL
					found = false;
					break;
				}

				if (sub_node->data == temp_root_node_pointer->data){
					//Increment both pointers and compare again
					sub_node = sub_node->link;
					temp_root_node_pointer = temp_root_node_pointer->link;
				}
				else{
					//Even if 1 is wrong, we know to return null
					found = false;
					break;
				}
			}


			if (found){
				return this_node_pointer;
			}
			
		}

		this_node_pointer = this_node_pointer->link;
	}

	return NULL;
}




int main() {
	Node *root;

	root = new Node(5);
	//std::cout << root->data << std::endl;
	root->link = new Node(7);
	root->link->link = new Node(9);
	root->link->link->link = new Node(1);


	std::cout << "Original list: " << std::endl;
	print_node(root);



	std::cout << "List to splice in" << std::endl;
	Node* splice_list = new Node(6);
	splice_list->link = new Node(3);
	splice_list->link->link = new Node(2);
	print_node(splice_list);




	Node* splice_pointer = new Node(7);
	std::cout << "Splicing list into orignal list" << std::endl;
	splice_in(root, splice_list, splice_pointer);

	std::cout << "Modified list" << std::endl;
	print_node(root);
	//print_node(splice_list);

	std::cout << "SEARCH FOR SUBLIST" << std::endl;


	Node* node_2 = new Node(5);
	node_2->link = new Node(7);
	node_2->link->link = new Node(6);
	node_2->link->link->link = new Node(9);
	node_2->link->link->link->link = new Node(3);
	node_2->link->link->link->link->link = new Node(9);
	node_2->link->link->link->link->link->link = new Node(1);

	std::cout << "Printing list to search: " << std::endl;
	print_node(node_2);


	Node* sub_list = new Node(9);
	sub_list->link = new Node(1);
	//sub_list->link->link = new Node(3);


	std::cout << "Printing sublist" << std::endl;

	print_node(sub_list);

	Node* sub_list_pointer = search_sub_list(node_2, sub_list);
	print_node(sub_list_pointer);


	system("pause");
}






