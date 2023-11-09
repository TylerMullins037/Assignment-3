#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
#include <list>

class Queue {
private:
    list<int> queueList;

public:
    void enqueue(int value);
    int dequeue();
    int frontElement();
    bool isEmpty();
    int size();
};

#endif
