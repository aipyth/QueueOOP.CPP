#pragma once

template <typename T>
class Node {
public:
	Node() {};
	Node(T value) : data(value) {};
	Node(const Node& x) : data(x.data) {};
	T getData() { return data; };
	void setData(T value) { data = value; };
	Node* getNext() { return next; };
	void setNext(Node* x) { next = x; };
private:
	T data = 0;
	Node* next = nullptr;
};

template <typename T>
class OneDirectionQueue {
public:
	OneDirectionQueue() {};
	OneDirectionQueue(const OneDirectionQueue<T>&);
	~OneDirectionQueue();
	void push(T x);
	void push(Node<T> *x);
	Node<T>* pop();
	bool empty() { return length == 0; };
private:
	unsigned int length = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
};

template<typename T>
OneDirectionQueue<T>::OneDirectionQueue(const OneDirectionQueue<T>& x)
{

}

template<typename T>
inline OneDirectionQueue<T>::~OneDirectionQueue()
{
	while (!this->empty()) {
		delete this->pop();
	}
}

template<typename T>
void OneDirectionQueue<T>::push(T x)
{
	Node<T>* new_node = new Node<T>(x);
	if (this->empty()) {
		head = tail = new_node;
	}
	else {
		head->setNext(new_node);
		head = new_node;
	}
	length++;
}

template<typename T>
void OneDirectionQueue<T>::push(Node<T> *x)
{
	Node<T> new_node = (*x);
	if (this->empty()) {
		head = tail = (&new_node);
	}
	else {
		head->setNext(&new_node);
		head = (&new_node);
	}
	length++;
}

template <typename T>
Node<T>* OneDirectionQueue<T>::pop()
{
	if (this->empty())
		throw "End of queue";

	Node<T>* poped = tail;
	tail = tail->getNext();
	length--;
	return poped;
}


