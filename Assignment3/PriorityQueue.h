#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#define NDEBUG

#include <iostream>
#include <assert.h>
#include <stdexcept>
using namespace std;

template<typename T, int capacity>
class PriorityQueue {
public:
    PriorityQueue();
    PriorityQueue(T queue[], int size) throw (runtime_error);
    void insert(T value) throw (runtime_error);
    void remove() throw (runtime_error);
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    void print() const;
private:
    T queue[capacity];
    int size;
    int indexOfHighPriority;

    void findTheHighPriority();
};

template<typename T, int capacity>
PriorityQueue<T, capacity>::PriorityQueue() {
    indexOfHighPriority = -1;
    size = 0;

    assert(size == 0);
}

template<typename T, int capacity>
PriorityQueue<T, capacity>::PriorityQueue(T queue[], int size) throw (runtime_error) {
    assert(capacity >= size);

    if (capacity < size) {
        throw runtime_error("Size is bigger than Capacity.");
    }

    indexOfHighPriority = -1;

    for (int i = 0 ; i < size ; i++) {
        this->queue[i] = queue[i];
    }
    this->size = size;

    assert(this->size == size);
}

template<typename T, int capacity>
void PriorityQueue<T, capacity>::insert(T value) throw (runtime_error) {
    assert(size < capacity);

    if (!isFull()) {
        queue[size] = value;
        size++;

        if (indexOfHighPriority == -1) {
            findTheHighPriority();
        } else {
            if (queue[indexOfHighPriority] < value) {
                indexOfHighPriority = size - 1;
            }
        }
    } else {
        throw runtime_error("Queue is full.");
    }

    assert(size <= capacity);
}

template<typename T, int capacity>
void PriorityQueue<T, capacity>::remove() throw (runtime_error) {
    assert(size > 0);

    if (!isEmpty()) {
        if (indexOfHighPriority == -1) {
            findTheHighPriority();
        }

        size--;
        if (size != 0) {
            for (int i = indexOfHighPriority + 1; i < size ; i++) {
               queue[i - 1] = queue[i];
            }
        }
    } else {
        throw runtime_error("Queue is empty.");
    }
}

template<typename T, int capacity>
bool PriorityQueue<T, capacity>::isEmpty() const {
    return size == 0;
}

template<typename T, int capacity>
bool PriorityQueue<T, capacity>::isFull() const {
    return size == capacity;
}

template<typename T, int capacity>
int PriorityQueue<T, capacity>::getSize() const {
    return size;
}

template<typename T, int capacity>
void PriorityQueue<T, capacity>::findTheHighPriority() {
    T value = queue[0];
    this->indexOfHighPriority = 0;

    for (int i = 1 ; i < size ; i++) {
        if (value < queue[i]) {
            this->indexOfHighPriority = i;
        }
    }
}

template<typename T, int capacity>
void PriorityQueue<T, capacity>::print() const {
    cout << "Queue elements : [ ";
    for (int i = 0 ; i < size ; i++) {
        cout << queue[i] << ' ';
    }
    cout << "]" << endl;
    cout << "Queue Capacity: " << capacity << endl;
    cout << "Queue Size: " << size << endl;
}
#endif