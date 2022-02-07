#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#define NDEBUG

#include <iostream>
#include <assert.h>
#include <stdexcept>
using namespace std;


// 1. What is the order of complexity of the methods implemented?
// O(n): print(), insert(), remove() -> O(1): isEmpty(), isFull(), getSize()
//
// 2. What would be the list of attributes if we implement a dynamic structure?
// - T* queue : Create the memory dynamically based on the elements.
// - int capacity : Capacity will be chaged by adding the elements. 
// - int size : Current size
// - int indexOfHighPriority : This is for my code. (Optional) To store the high priority index, it can make add and delete easy.
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
    int indexOfHighPriority;        // This attribute will store the High Priority index. If the high priority is not searched, the value will be -1.

    void findTheHighPriority();
};

// Complexity
// - Best case : O(1)
// - Worst case : O(1)
template<typename T, int capacity>
PriorityQueue<T, capacity>::PriorityQueue() {
    indexOfHighPriority = -1;
    size = 0;

    // Size should be 0 and indexOfHighPriority should be -1. 
    assert(size == 0);
    assert(indexOfHighPriority == -1);
}

// Complexity
// - Best case : O(n)
// - Worst case : O(n)
template<typename T, int capacity>
PriorityQueue<T, capacity>::PriorityQueue(T queue[], int size) throw (runtime_error) {
    // Capacity should be greater than and eaqul to size. 
    assert(capacity >= size);

    if (capacity < size) {
        throw runtime_error("Size is bigger than Capacity.");
    }

    indexOfHighPriority = -1;

    for (int i = 0 ; i < size ; i++) {
        this->queue[i] = queue[i];
    }
    this->size = size;

    // size of the queue object should be same with the size of the queue. 
    assert(this->size == size);
    // indexOfHighPriority should be -1. 
    assert(indexOfHighPriority == -1);
}

// Complexity
// - Best case : O(1)
//   . Element is added. 
// - Worst case : O(n)
//   . indexOfHighPriority is not searched. 
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

// Complexity
// - Best case : O(1)
//   . Size == 1
// - Worst case : O(n)
//   . indexOfHighPriority is not searched. 
//   . Element is removed. 
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

// Complexity
// - Best case : O(1)
// - Worst case : O(1)
template<typename T, int capacity>
bool PriorityQueue<T, capacity>::isEmpty() const {
    return size == 0;
}

// Complexity
// - Best case : O(1)
// - Worst case : O(1)
template<typename T, int capacity>
bool PriorityQueue<T, capacity>::isFull() const {
    return size == capacity;
}

// Complexity
// - Best case : O(1)
// - Worst case : O(1)
template<typename T, int capacity>
int PriorityQueue<T, capacity>::getSize() const {
    return size;
}

// Complexity
// - Best case : O(n)
// - Worst case : O(n)
template<typename T, int capacity>
void PriorityQueue<T, capacity>::findTheHighPriority() {
    assert(size > 0);

    if (size > 0) {
        T value = queue[0];
        indexOfHighPriority = 0;

        for (int i = 1 ; i < size ; i++) {
            if (value < queue[i]) {
                indexOfHighPriority = i;
            }
        }
    } else {
        indexOfHighPriority = -1;
    }
}

// Complexity
// - Best case : O(n)
// - Worst case : O(n)
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