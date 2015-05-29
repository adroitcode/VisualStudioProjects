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



void print_list(std::vector<int> list){
	std::cout << "[";
	for (size_t x = 0; x < list.size(); x++){
		std::cout << std::to_string(list[x]) + ", ";
	}

	std::cout << "]";

	std::cout << std::endl;
}

class Sequence {
	private:

		Node* node;
		int index;
	public:

		Sequence(){
			index = 0;
			node = nullptr;

		}


		void reset(){
			index = 0;
		}


		void add(int num){


			Node* current_node = get_node(index);
			

			if (current_node){
				Node* next_node = current_node->link;
				current_node->link = new Node(num);

				if (next_node){
					current_node->link->link = next_node;
				}

				index++;
			}
			else if(index != -1){
				//Create node at 0 position
				node = new Node(num);
			}

			
		}


		void next(){
			Node* current_node = get_node(index);
			if (current_node){
				if (current_node->link){
					index++;
					//std::cout << "next index: " + std::to_string(index);
				}
				else{
					index = -1;
				}
			}
		}



		bool valid(){
			if (index != -1 && get_node(index)){
				return true;
			}
			else{
				return false;
			}
		}



		void clear(){
			index = 0;
			delete node;
			node = nullptr;

		}




		void display(){
			display(" ");
		}


		void display(std::string const &seperation_char){
			Node* this_node = node;
			while (this_node){
				std::cout << std::to_string(this_node->data) + seperation_char;
				this_node = this_node->link;
			}

			std::cout << std::endl;
			
		}

		Node* data(){
			return get_node(index);
		}

		Node* get_node(int x_index){
			Node* temp_node = node;
			int counter = 0;
			while (temp_node){
				if (x_index == counter){
					return temp_node;
				}

				temp_node = temp_node->link;
				counter++;
			}

			return nullptr;
		}

		void remove(){
			Node* previous_node = get_node(index - 1);
			Node* current_node = get_node(index);
			Node* next_node = current_node->link;

			if (previous_node){
				previous_node->link = next_node;

				
			}


			delete current_node;
		}
};


int main() {
	Sequence s;
	for (int i = 0; i < 6; ++i){
		s.add(i);
	}
	s.display();
	std::cout << "==========\n";
	s.reset();
	for (int i = 0; i < 3; ++i){
		s.next();
	}
	s.add(42);
	s.display();


	std::cout << "==========\n";
	s.reset();



	for (int i = 0; i < 2; ++i){
		s.next();
	}
	s.remove();
	s.display();
	std::cout << "==========\n";
	s.clear();
	s.display();
	std::cout << "==========\n";


	system("pause");
}