#include "Queue.h"

void Queue::enqueue(int value) {
    queueList.push_back(value);
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw exception("Queue is empty");
    }

    int frontValue = queueList.front();
    queueList.pop_front();
    return frontValue;
}

int Queue::frontElement() {
    if (isEmpty()) {
        throw exception("Queue is empty");
    }

    return queueList.front();
}

bool Queue::isEmpty() {
    return queueList.empty();
}

int Queue::size() {
    return queueList.size();
}
