#pragma once
#include<iosfwd>

namespace containers {
	template<typename T>
	class LinkedList {
	private:

		enum ERROR : int { index_out_of_bounds, empty_list };

		struct Node {
			T val;
			Node* next = nullptr;
		};

		Node* HEAD = nullptr;
		size_t nodes = 0; //keep track of the number of nodes

		void raiseError(ERROR code) {
			if (code == ERROR::index_out_of_bounds) {
				std::cerr << "Index out of bounds" << std::endl;
			}
			else if (code == ERROR::empty_list) {
				std::cerr << "Please add nodes to the list" << std::endl;
			}
		};

		Node* getPtrtoNode(const size_t index) {
			if (index <= nodes - 1) {
				Node* current_node = HEAD;
				size_t counter = 0;
				while (counter != index) {
					current_node = current_node->next;
					counter++;
				}
				return current_node;
			}
			else {
				raiseError(ERROR::index_out_of_bounds);
				return nullptr;
			}

		}
	public:
		//create a node and set its value
		void addNode(const T& val) {
			if (nodes == 0) {
				HEAD = new Node;
				HEAD->val = val;
				nodes++;
			}
			else {
				auto temp = getPtrtoNode(nodes - 1);//get a pointer to the last node
				temp->next = new Node;
				temp->next->val = val;
				nodes++;
			}
		}

		void deleteNode(const size_t index) {
			if (nodes != 0) {
				auto prev_node = getPtrtoNode(index - 1);
				auto current_node = prev_node->next;
				auto next_node = current_node->next;
				prev_node->next = next_node;
				delete current_node;
				nodes--;
			}
			else {
				raiseError(ERROR::empty_list);
			}
		}

		void insertNode(const size_t index, const T &val) {
			auto prev_node = getPtrtoNode(index - 1);
			auto current_node = prev_node->next;
			prev_node->next = new Node;
			prev_node->next->next = current_node;
			prev_node->next->val = val;
			nodes++;
		}

		void setVal(const size_t index, const T& val) {
			auto current_node = getPtrtoNode(index);
			current_node->val = val;
		}

		T getVal(const size_t index) { 
			return getPtrtoNode(index)->val; 
		}
	};
}