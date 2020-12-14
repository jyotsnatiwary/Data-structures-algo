#include <iostream>
using namespace std;

template <typename T>
class Node {
	public : 
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}

		~Node() {
			delete next;
		}
};

template <typename T>
class Stack {
	Node<T> *head;
	int size;		// number of elements prsent in stack

	public :

	Stack() {

	}

	int getSize() {
		
	}

	bool isEmpty() {

	}

	void push(T element) {

	}

	T pop() {

	}

	T top() {

	}
};

