#include<iostream>
#include<chrono>
#include"containers.h"
template<typename T>
struct Node {
	T val;
	Node<T>* next = nullptr;
};
template<typename T>
struct LinkedList {
private:
	Node<T>* HEAD = nullptr; //pointer to the first node in the list

public:
	void addNode(const T &val) {
		if (HEAD == nullptr) {
			HEAD = new Node<T>;
			HEAD->val = val;
		}
		else {
			auto n = HEAD; //dummy variable to step through the linked list
			while (n->next!=nullptr) {//check if the current node to points to nothing
				n = n->next; //if the current node points to next node move to that node
			}
			n->next = new Node<T>; //the current node points to nothing so create a new node
			n->next->val = val; // assign the val given to the node after the current node	
		}
	}

	//get the value at the specified index, linked list starts at 0
	T getVal(const size_t index) {
		bool error = false;
		auto n = HEAD; //dummy variable to step through the list
		size_t counter = 0;//counter to keep track of the current position in the list
		while (counter != index) {
			if (n == nullptr) {
				std::cerr << "Index Out of Bounds" << std::endl;
				error = true;
				break;
			}
			else {
				n = n->next;
				counter++;
			}
		}
		if (error) {
			return 0;//default value to return if an out of bound error occurs
		}
		else {
			return n->val;
		}		
	}

	//delete node at index
	void deleteNode(const size_t index) {
		if (HEAD != nullptr) {
			Node<T>* n = HEAD; //dummy variable to step through the list
			size_t counter = 0; //counter to keep track of position
			bool error = false;
			//pointers to represent nodes before and after the current node
			Node<T>* prev_node = nullptr;
			Node<T>* next_node = n->next;
			while (counter != index) {
				//if the next node pointer is nullpointer break the loop
				if (next_node == nullptr) {
					error = true;
					std::cerr << "Index Out of Bounds" << std::endl;
					break;
				}
				else {
					prev_node = n;  //set the previous node pointer  to point to the current node
					next_node = next_node->next; //set the next node pointer to point to the node after it
					n = n->next; //move the current node pointer to the next node
					++counter;
				}
				
			}
			if (!error) {

				if (index == 0) { //special case if the first element is to be deleted we need to set HEAD equal to next_node
								 //that is the 2nd element in the list next_node points to the second element
					HEAD = next_node; 
					delete n;
				}
				else {
					prev_node->next = next_node; //make the previous node pointer point to the next node
					delete n; //delete the current node
				}
				
			}			
		}
		else {
			std::cerr << "Please add nodes to the list" << std::endl;
		}
	}

	void insertNode(const size_t index, const T& val) {
		if (HEAD != nullptr) {
			Node<T>* n = HEAD;
			Node<T>* prev_node = nullptr;
			size_t counter = 0;
			while (counter != index) {
				if (n != nullptr) {
					prev_node = n;
					n = n->next;
					counter++;
				}
				else {
					
					std::cerr << "Index out of bounds" << std::endl;
					goto err;
				}
				
			}
			prev_node->next = new Node<T>;
			prev_node->next->next = n;
			prev_node->next->val = val;
		}
		else {
		err:
			std::cerr << "Please add nodes to the list" << std::endl;
		}
	}

	void setVal(const size_t index, const T& val) {
		if (HEAD != nullptr) {
			Node<T>* n = HEAD;
			size_t counter = 0;
			while (counter!=index) {
				if (n != nullptr) {
					n = n->next;
				}
			}
			n->val = val;
		}
		else {
			std::cerr << "Please add nodes to the list" << std::endl;
		}
	}
	
};



//timer for benchmarking the performance... copy pasted lol
struct Timer{
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
	Timer(){
		startTime = std::chrono::high_resolution_clock::now();
	}
	~Timer() {
		auto endTime = std::chrono::high_resolution_clock::now();
		

		auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(startTime).time_since_epoch().count();
		auto end  = std::chrono::time_point_cast<std::chrono::milliseconds>(endTime).time_since_epoch().count();
		auto diff = end - start;

		std::cout << "time taken: " << diff << "ms" << "\n";
	}
	
};


int main() {
	
	std::cout << "Starting containers::LinkedList benchmark" << std::endl;
	{
		Timer time1;
		containers::LinkedList<int> list;
		std::cout << "populating list" << "\n";
		for (int i = 0; i < 10; ++i) {
			list.addNode(i);
		}
		std::cout << "list populated\n printing list..." << "\n";
		for (int i = 0; i < 10; ++i) {
			std::cout << list.getVal(i) << "\n";
		}
		std::cout << "deleting node 5" << "\n";
		list.deleteNode(5);
		std::cout << "new node at index 5" << "\n";
		std::cout << list.getVal(5) << "\n";
		std::cout << "inserting new node at index 5" << "\n";
		list.insertNode(5, 20);
		std::cout << "node inserted printing the list" << "\n";
		for (int i = 0; i < 10; ++i) {
			std::cout << list.getVal(i) << "\n";
		}
	}
	/*
	std::cout << "Starting LinkedList benchmark" << std::endl;
	{
		Timer time2;
		LinkedList<int> list;
		std::cout << "populating list" << "\n";
		for (int i = 0; i < 10; ++i) {
			list.addNode(i);
		}
		std::cout << "list populated\n printing list..." << "\n";
		for (int i = 0; i < 10; ++i) {
			std::cout << list.getVal(i) << "\n";
		}
		std::cout << "deleting node 5" << "\n";
		list.deleteNode(5);
		std::cout << "new node at index 5" << "\n";
		std::cout << list.getVal(5) << "\n";
		std::cout << "inserting new node at index 5" << "\n";
		list.insertNode(5, 20);
		std::cout << "node inserted printing the list" << "\n";
		for (int i = 0; i < 10; ++i) {
			std::cout << list.getVal(i) << "\n";
		}
	}
	*/

	return 0;
}