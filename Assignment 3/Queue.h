// Queue.h

#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
#include <list>

// Declaration of the Queue class template
template <typename ItemType>
class Queue {
private:
    // Private member variable to store the elements of the queue using a linked list
    std::list<ItemType> queueList;

public:
    // Public member functions for basic queue operations

    // Enqueue: Add an element to the back of the queue
    void enqueue(const ItemType& value);

    // Dequeue: Remove and return the front element of the queue
    ItemType dequeue();

    // Top: Get the value of the front element without removing it
    ItemType top();

    // IsEmpty: Check if the queue is empty
    bool isEmpty();

    // Size: Get the number of elements in the queue
    int size();
};


#endif
