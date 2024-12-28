#include "classes.h"

int main()
{
	//Test
	Queue<int> q1, q2, q3, q4, q5;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	Node<int>* pointer = q1.clone(q2);
	while (pointer)
	{
		cout << pointer->_data << " ";
		pointer = pointer->_next;
	}
	cout << endl;
	q3.enqueue(60);
	q3.enqueue(70);
	q3.enqueue(80);
	q3.enqueue(90);
	q3.enqueue(100);
	Node<int>* pointer2 = q2 + q3;
	while (pointer2)
	{
		cout << pointer2->_data << " ";
		pointer2 = pointer2->_next;
	}
	cout << endl;
	Node<int>* pointer3 = q1.clone(q4);
	q5.enqueue(30);
	q5.enqueue(40);
	q5.enqueue(50);
	q5.enqueue(60);
	q5.enqueue(70);
	Node<int>* pointer4 = q4 * q5;
	while (pointer4)
	{
		cout << pointer4->_data << " ";
		pointer4 = pointer4->_next;
	}
	return 0;
}