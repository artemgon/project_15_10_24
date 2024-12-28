#include "libs.h"

template <class T>
struct Node
{
	T _data;
	Node<T>* _next;
	Node<T>* _prev;
};

template <class T>
class Queue
{
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size;
public:
	Queue() : _head(NULL), _tail(NULL), _size(0) {}
	~Queue()
	{
		while (_head)
		{
			Node<T>* temp = _head;
			_head = _head->_next;
			delete temp;
		}
	}
	void enqueue(T data)
	{
		Node<T>* temp = new Node<T>;
		temp->_data = data;
		temp->_next = NULL;
		temp->_prev = _tail;
		if (_tail)
			_tail->_next = temp;
		_tail = temp;
		if (!_head)
			_head = _tail;
		_size++;
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return;
		}
		Node<T>* temp = _head;
		_head = _head->_next;
		if (_head == nullptr)
			_tail = nullptr;
		delete temp;
		_size--;
	}
	T peek()
	{
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		return _head->_data;
	}
	Node<T>* clone(Queue<T>& q) const
	{
		Node<T>* temp = _head;
		while (temp)
		{
			q.enqueue(temp->_data);
			temp = temp->_next;
		}
		return q._head;
	}
	Node<T>* operator+(Queue<T>& q) const
	{
		Queue<T>* temp = new Queue<T>;
		Node<T>* tempNode = _head;
		while (tempNode)
		{
			temp->enqueue(tempNode->_data);
			tempNode = tempNode->_next;
		}
		tempNode = q._head;
		while (tempNode)
		{
			temp->enqueue(tempNode->_data);
			tempNode = tempNode->_next;
		}
		return temp->_head;
	};
	Node<T>* operator*(Queue<T>& q) const
	{
		Queue<T>* temp = new Queue<T>;
		Node<T>* tempNode = _head;
		while (tempNode)
		{
			Node<T>* tempNode2 = q._head;
			while (tempNode2)
			{
				if (tempNode->_data == tempNode2->_data)
				{
					temp->enqueue(tempNode->_data);
					break;
				}
				tempNode2 = tempNode2->_next;
			}
			tempNode = tempNode->_next;
		}
		return temp->_head;
	}
	void print() const
	{
		Node<T>* temp = _head;
		while (temp)
		{
			cout << temp->_data << " ";
			temp = temp->_next;
		}
		cout << endl;
	}
	bool isEmpty()
	{
		return _size == 0;
	}
	int getSize()
	{
		return _size;
	}
};