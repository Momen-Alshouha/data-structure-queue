#include <iostream>
#include "queue.h";

int main()
{
	Queue<> queue(0);

	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.print();
	cout << "front : " << queue.front << endl;
	cout << "rear : " << queue.rear << endl;
	cout <<"size : " << queue.size << endl;
	cout << boolalpha << queue.IsEmpty() << endl;
	/*
	queue.clear();
	cout << "front : " << queue.front << endl;
	cout << "rear : " << queue.rear << endl;
	cout << "size : " << queue.size << endl;
	cout << boolalpha << queue.IsEmpty() << endl;
	*/

	// copy constructor
	Queue<> NewQueue = queue; // assignment using "=" operator overloading
	NewQueue.print();
}
