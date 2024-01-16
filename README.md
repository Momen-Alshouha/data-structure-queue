# Queue Implementation in C++ Using Linked-List

This repository contains a C++ template class implementing a linked-list-based queue, adhering to Object-Oriented Programming principles.

## Features

- **Enqueue:** Add an element to the back of the queue.
- **Dequeue:** Remove and return the element from the front of the queue.
- **Front:** Get the data of the front element.
- **Rear:** Get the data of the rear element.
- **Size Tracking:** Keep track of the number of elements in the queue.
- **Copy Constructor:** Create a copy of the queue.

## Usage

To use this implementation, follow these steps:

1. Clone the repository.
2. Include the necessary header file in your C++ code: `Queue.h`.
3. Create a `Queue` object and utilize its functionalities as needed.

```cpp
#include <iostream>
#include "queue.h"

int main()
{
    // Create a Queue object with a default value of 0
    Queue<> queue(0);

    // Enqueue elements into the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Print the elements of the queue
    queue.print();

    // Display front, rear, size, and whether the queue is empty
    std::cout << "front: " << queue.front << std::endl;
    std::cout << "rear: " << queue.rear << std::endl;
    std::cout << "size: " << queue.size << std::endl;
    std::cout << "Is empty: " << std::boolalpha << queue.IsEmpty() << std::endl;

    /*
    queue.clear();
    std::cout << "front: " << queue.front << std::endl;
    std::cout << "rear: " << queue.rear << std::endl;
    std::cout << "size: " << queue.size << std::endl;
    std::cout << "Is empty: " << std::boolalpha << queue.IsEmpty() << std::endl;
    */

 // Example with a Queue of strings
    Queue<string> stringQueue("Default");
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    stringQueue.enqueue("C++");
    stringQueue.print();

    // Display front, rear, size, and whether the queue is empty for the string queue
    std::cout << "\nString Queue:" << std::endl;
    std::cout << "front: " << stringQueue.front << std::endl;
    std::cout << "rear: " << stringQueue.rear << std::endl;
    std::cout << "size: " << stringQueue.size << std::endl;
    std::cout << "Is empty: " << std::boolalpha << stringQueue.IsEmpty() << std::endl;

    // Copy constructor example
    Queue<> newQueue = queue;  // Copy the contents of the existing queue
    newQueue.print();

    return 0;
}
