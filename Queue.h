#include <iostream>
using namespace std;

template<typename T = int>
class Queue
{
private:
	struct Item
	{
		T Data;
		Item* next;

		Item(T value) {
			Data = value;
			next = nullptr;
		}
	};

	using ptrItem = Item*; // alias

	ptrItem _front;
	ptrItem _rear;
	size_t _size;
	T _defaultData; // default data to avoid return garbage data if queue is empty

public:

	Queue(const T defaultData);
	Queue(const Queue<T>& sourceQueue); // copy constructor
	~Queue();

	Queue& operator=(const Queue& other) { // operator " = " overloading
		if (this != &other) { // other is the object we are copying from
			clear();
			ptrItem DistanceFront = other._front;
			while (DistanceFront != nullptr) {
				enqueue(DistanceFront->Data);
				DistanceFront = DistanceFront->next;
			}
		}
		return *this;
	}



	// Getters
	T GetFrontData() {
		if (_front!=nullptr)
		{
			return _front->Data;
		}
		return _defaultData;
	}

	T GetReartData() {
		if (_rear!=nullptr)
		{
			return _rear->Data;
		}
		return _defaultData;
	}

	size_t GetSize() {
		return _size;
	}

	// read only proprties
	__declspec(property(get = GetFrontData)) T front;
	__declspec(property(get = GetReartData)) T rear;
	__declspec(property(get = GetSize)) size_t size;


	bool IsEmpty() const {
		return (_size == 0);
	}

	void clear() { //  Remove all elements from the queue.
		
			while (_front) {
				ptrItem temp = _front;
				_front = _front->next; // Move to the next before delete ; if we move first then we can't delete
				delete temp;
			}

			_rear = nullptr;
			_size = 0;

	}

	void enqueue(T value) { // Add an element to the back of the queue

		Item* NewItem = new Item(value);

		if (_front == nullptr)
		{
			_front = NewItem;
			_rear = NewItem;
		}
		else {
			_rear->next = NewItem;
			_rear = NewItem;
		}
		_size++;
	}

	T dequeue() { // Remove and return the element from the front of the queue
		if (_front!=nullptr)
		{
			if (_front==_rear)
			{
				T data = _front->Data;
				_front = _rear = nullptr;
				return data;
			}
			ptrItem ToDelete = _front;
			_front = _front->next;
			delete ToDelete;
			_size--;
		}
	}


	void print() const {
		if (_front!=nullptr)
		{
			cout << "Queue from front to back : ";
			ptrItem front = _front;
			while (front != nullptr)
			{
				cout << front->Data;
				if (front != _rear)
				{
					cout << " -> ";
				}
				front = front->next;
			}
			cout << endl;
			delete front;
		}
	}
};

template<typename T>
Queue<T>::Queue(T defaultData) :_defaultData(defaultData), _front(nullptr), _rear(nullptr), _size(0) {}

template<typename T>
Queue<T>::Queue(const Queue<T>& sourceQueue) : _defaultData(sourceQueue._defaultData), _front(nullptr), _rear(nullptr), _size(0) {
	
	// Copy the contents of the source queue
	ptrItem sourceFront = sourceQueue._front;
	while (sourceFront != nullptr) {
		enqueue(sourceFront->Data);
		sourceFront = sourceFront->next;
	}
}


template<typename T>
Queue<T>::~Queue()
{
	clear();
}