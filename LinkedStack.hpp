/***************************************************************
Chris Schulstad
LinkedStack.hpp
A stack with linked list implementation
***************************************************************/

#ifndef _LINKED_STACK_GUARD
#define _LINKED_STACK_GUARD 1

#include <iostream>

using namespace std;

class LinkedStack {

// Private node class to facilitate linked list
private:
	class Node {
	public:
		std::string _data;
		Node* _next;

		Node() {
			_data = "";
			_next = NULL;
		}
	};

// Class Member Functions
public:
	// LinkedList instance variables
	unsigned _size;
	Node* _head;

	LinkedStack() {
		_head = NULL;
		_size = 0;
	}

	LinkedStack(const LinkedStack& myStack) {
		_head = myStack._head;
		_size = myStack._size;
	}

	~LinkedStack() {
		clear();
	}

	// TODO - fix
	const LinkedStack& operator=(const LinkedStack& myStack) {
		_head = myStack._head;
		_size = myStack._size;
	}

	// Returns the data from the link of specified index
	std::string operator[](int n) const {
		// Handles special cases
		if (n >= _size) throw ("Out of bounds. The specified index is > the size of the LinkedList");

		// Locates the Link of the specific index in the LinkedList
		Node* current = _head;
		for (int i = 0; i < n; i++) {
			current = current->_next;
		}

		std::string retString = current->_data;
		return retString;
	}

	// Returns true if the LinkedList is empty
	bool isEmpty() const {
		return (_head == NULL);
	}

	// Returns the size (int) of the LinkedList
	int size() const {
		return _size;
	}

	// Adds a new Link to the left of the LinkedStack
	void push(const std::string& item) {
		Node* newNode = new Node();
		newNode->_data = item;
		newNode->_next = _head;

		_head = newNode;
		_size++;
	}

	// Removes a Link from the left of the LinkedStack
	std::string pop() {
		// Handles special cases
		if (isEmpty()) throw("Empty LinkedStack");

		std::string retString = _head->_data;

		// Deletes the node, and points the head to the next element
		Node* temp = _head;
		_head = _head->_next;
		delete temp;

		_size--;
		return retString;
	}

	// Returns the data (std::string) from the head
	std::string top() {
		return _head->_data;
	}

	// Returns true if a link (with specified data) is found
	bool contains(const std::string& myString) const {
		Node* current = _head;

		// Searches for the link (w/ specified data) and returns true if found
		for (int i = 0; i < _size; i++) {
			if (current->_data == myString) {
				return true;
			}
			else current = current->_next;
		}

		//delete current;
		return false;
	}

	// Returns true if a link (with specified data) is found, and deletes it.
	bool remove(const std::string& myString) {
		Node* current = _head;
		Node* previous = NULL;

		// Attempts to locate and remove the link (with specified data)
		for (int i = 0; i < _size; i++) {
			if (current->_data == myString) {
				if (current == _head) _head = current->_next;
				else previous->_next = current->_next;

				_size--;
				delete current;
				return true;
			}
			else {
				previous = current;
				current = current->_next;
			}
		}

		return false;
	}

	// Removes all links from the LinkedStack
	void clear() {
		while (_head != NULL) {
			Node* temp = _head;
			_head = _head->_next;
			delete temp;
		}
		_size = 0;
	}

	// Overloaded output operator
	friend std::ostream& operator<<(std::ostream& os, const LinkedStack& ell)
	{
		for (Iterator itr = ell.begin(); itr != ell.end(); )
		{
			os << *itr;
			itr++;
			if (itr != ell.end()) os << ", ";
		}

		return os;
	}

};

#endif
