#include "libs.h"

template <typename T>
struct Node {
	T _data;
	Node<T>* _next;
	Node<T>* _prev;
	Node(T data) : _data(data), _next(nullptr), _prev(nullptr) {}
};

template <typename T>
class Array
{
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size, _capacity, _grow;
public:
	Array(int initSize, int growBy = 1) : _head(nullptr), _tail(nullptr), _size(0), _capacity(initSize), _grow(growBy)
	{
		if (growBy <= 0)
		{
			cout << "Error.Invalid grow value..." << endl;
			exit(1);
		}
	}
	int GetSize()  const { return _capacity; }
	void SetSize(int size, int grow = 1) {
		if (grow <= 0) {
			cout << "Error. Invalid grow value..." << endl;
			exit(1);
		}
		if (size < _size) {
			int removeCount = _size - size;
			for (int i = 0; i < removeCount; ++i) {
				RemoveAt(_size - 1);
			}
		}
		else if (size > _size) {
			for (int i = _size; i < size; ++i) {
				Add(T());  
			}
		}
		_capacity = size;
		_grow = grow;
	}
	int GetUpperBound() const { return _size - 1; }
	bool IsEmpty() const { return _size == 0; }
	void FreeExtra()
	{
		if (_size < _capacity)
		{
			_capacity = _size;
		}
	}
	void RemoveAll()
	{
		while (_head)
		{
			Node<T>* temp = _head;
			_head = _head->_next;
			delete temp;
		}
		_head = _tail = nullptr;
		_size = 0;
		_capacity = 0;
	}
	T GetAt(int index) const {
		if (index < 0 || index >= _size) {
			cout << "Error. Invalid index..." << endl;
			exit(1);
		}
		Node<T>* temp = _head;
		for (int i = 0; i < index; i++) {
			temp = temp->_next;
		}
		return temp->_data;
	}
	void SetAt(int index, T data)
	{
		if (index < 0 || index >= _size)
		{
			cout << "Error.Invalid index..." << endl;
			exit(1);
		}
		Node<T>* temp = _head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->_next;
		}
		temp->_data = data;
	}
	T& operator[](int index) {
		if (index < 0 || index >= _size) {
			cout << "Error. Invalid index..." << endl;
			exit(1);
		}
		Node<T>* temp = _head;
		for (int i = 0; i < index; i++) {
			temp = temp->_next;
		}
		return temp->_data;
	}
	void Add(T data)
	{
		if (_size >= _capacity)
		{
			_capacity += _grow;
		}
		Node<T>* newNode = new Node<T>(data);
		if (!_head)
		{
			_head = _tail = newNode;
		}
		else
		{
			_tail->_next = newNode;
			newNode->_prev = _tail;
			_tail = newNode;
		}
		_size++;
	}
	void Append(const Array<T>& other)
	{
		Node<T>* current = other._head;
		while (current)
		{
			Add(current->_data);
			current = current->_next;
		}
	}
	Array<T>& operator = (const Array<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}
		RemoveAll();
		Node <T>* current = other._head;
		while (current)
		{
			Add(current->_data);
			current = current->_next;
		}
		return *this;
	}
	T* GetData() const
	{
		T* arr = new T[_size];
		Node<T>* current = _head;
		for (int i = 0; i < _size; i++)
		{
			arr[i] = current->_data;
			current = current->_next;
		}
		return arr;
	}
	void InsertAt(int index, T value) {
		if (index < 0 || index > _size) {  
			cout << "Error. Invalid index..." << endl;
			exit(1);
		}
		Node<T>* newNode = new Node<T>(value);
		if (index == 0) {  
			newNode->_next = _head;
			if (_head) _head->_prev = newNode;
			_head = newNode;
			if (!_tail) _tail = _head; 
		}
		else if (index == _size) { 
			newNode->_prev = _tail;
			if (_tail) _tail->_next = newNode;
			_tail = newNode;
		}
		else {  
			Node<T>* current = _head;
			for (int i = 0; i < index - 1; i++) {
				current = current->_next;
			}
			newNode->_next = current->_next;
			newNode->_prev = current;
			if (current->_next) current->_next->_prev = newNode;
			current->_next = newNode;
		}
		_size++;
	}
	void RemoveAt(int index)
	{
		if (index < 0 || index >= _size)
		{
			cout << "Error.Invalid index..." << endl;
			exit(1);
		}
		Node<T>* current = _head;
		for (int i = 0; i < index; i++)
		{
			current = current->_next;
		}
		if (current->_prev) current->_prev->_next = current->_next;
		if (current->_next) current->_next->_prev = current->_prev;
		if (current == _head) _head = current->_next;
		if (current == _tail) _tail = current->_prev;
		delete current;
		_size--;
	}
	~Array() { RemoveAll(); }
};