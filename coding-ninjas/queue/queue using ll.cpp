template <typename T>
class Node {
	public : 
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}
};


template <typename T>
class Queue {
	Nod<T> *head;
	Node<T> *tail;
	int size;

	public : 

	Queue() {

	}

	int getSize() {

	}

	bool isEmpty() {

	}

	void enqueue(T element) {

	}

	T front() {
		
	}

	T dequeue() {

	}






};
