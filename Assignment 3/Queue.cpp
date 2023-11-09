// Queue.cpp

#include "Queue.h"
#include <stdexcept>

// Implementation of the enqueue function for adding an element to the back of the queue
template <typename ItemType>
void Queue<ItemType>::enqueue(const ItemType& value) {
    queueList.push_back(value);
}

// Implementation of the dequeue function for removing and returning the front element of the queue
template <typename ItemType>
ItemType Queue<ItemType>::dequeue() {
    // Check if the queue is empty before dequeuing
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    // Retrieve the front element, remove it, and return its value
    ItemType frontValue = queueList.front();
    queueList.pop_front();
    return frontValue;
}

// Implementation of the top function for getting the value of the front element without removing it
template <typename ItemType>
ItemType Queue<ItemType>::top() {
    // Check if the queue is empty before getting the front element
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    // Return the value of the front element
    return queueList.front();
}

// Implementation of the isEmpty function for checking if the queue is empty
template <typename ItemType>
bool Queue<ItemType>::isEmpty() {
    // Return true if the queue is empty, otherwise return false
    return queueList.empty();
}

// Implementation of the size function for getting the number of elements in the queue
template <typename ItemType>
int Queue<ItemType>::size() {
    // Return the size of the queue
    return queueList.size();
}

// Explicit instantiation of the Queue class with specific data types
template class Queue<int>;
template class Queue<std::string>;
template class Queue<double>;
template class Queue<char>;