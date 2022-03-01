#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, int capacity> // T is the generic type used for the items in the queue and capacity is the initial size of the queue
class Queue {
public:
	Queue(); // Creates an empty Queue object with the maximum size of "capacity"
    Queue(const Queue&); // Copy Constructor
    ~Queue(); // Desctructor

	void insert(const T& x); // Inserts x at the end of the queue; if required the queue is expanded (doubled)
	T remove(); // Removes and returns the first item of the queue (i.e. item at index 0), or throws an exception if the queue is empty,
	bool empty() const; // Returns true if the queue is empty, or false otherwise.
	int getSize() const; // Returns the number of items in the queue.
    void print() const;

    Queue& operator=(const Queue&);
    Queue operator+(const Queue&);
    void operator+=(const T&);
    Queue& operator--();
    Queue operator--(T);
    bool operator==(const Queue&);
    bool operator!=(const Queue&);

    friend ostream& operator<<(ostream& out, const Queue& obj) {
        for (int i = 0 ; i < obj.size ; i++) {
            out << obj.q[i] << ' ';
        }

        return out;
    }
private:
	T* q; // q points to the front of the queue in the heap
	int size; // size is the number of items in the queue
	int maxSize; // maxSize is the maximum size of the array pointed by q.

    void expand();
};

template <typename T, int capacity>
Queue<T, capacity>::Queue() {
    size = 0;
    maxSize = capacity;

    q = new T[maxSize];
}

// Need to ignore when instances are created using copy constructor
template <typename T, int capacity>
Queue<T, capacity>::Queue(const Queue& obj) {
    size = obj.size;
    maxSize = obj.maxSize;

    if (obj.q == nullptr) {
        q = nullptr;
    } else {
        q = new T[maxSize];

        for (int i = 0 ; i < size ; i++) {
            q[i] = obj.q[i];
        }
    }
}

template <typename T, int capacity>
Queue<T, capacity>::~Queue() {
    delete[] q;
}

template <typename T, int capacity>
void Queue<T, capacity>::insert(const T& x) {
    if (size == maxSize) {
        expand();
    }

    q[size++] = x;
}

template <typename T, int capacity>
T Queue<T, capacity>::remove() {
    if (size == 0) {
        throw std::runtime_error("Queue is empty.");
    } else {
        int value = q[0];
        
        for (int i = 1 ; i < size ; i++) {
            q[i - 1] = q[i];
        }
        size--;
        return value;
    }
}

template <typename T, int capacity>
bool Queue<T, capacity>::empty() const {
    return size == 0;
}

template <typename T, int capacity>
int Queue<T, capacity>::getSize() const {
    return size;
}

template <typename T, int capacity>
void Queue<T, capacity>::print() const {
    cout << "Queue - Size : " << size << ", Max size : " << maxSize << endl;
    cout << "Items : [ ";
    for (int i = 0 ; i < size ; i++) {
        cout << q[i] << ' ';
    }
    cout << "]" << endl;
}

template <typename T, int capacity>
Queue<T, capacity>& Queue<T, capacity>::operator=(const Queue& obj) {
    if (this == &obj) {
        return *this;
    }

    size = obj.size;
    maxSize = obj.maxSize;

    if (obj.q == nullptr) {
        q = nullptr;
    } else {
        delete[] q;

        q = new T[maxSize];

        for (int i = 0 ; i < size ; i++) {
            q[i] = obj.q[i];
        }
    }

    return *this;
}

template <typename T, int capacity>
Queue<T, capacity> Queue<T, capacity>::operator+(const Queue& obj) {
    if (obj.q == nullptr) {
        return *this;
    } else {
        Queue<T, capacity> newQueue;

        newQueue.size = size + obj.size;
        newQueue.maxSize = maxSize + obj.maxSize;

        T* temp = new T[newQueue.maxSize];

        for (int i = 0 ; i < size ; i++) {
            newQueue.q[i] = q[i];
        }

        for (int i = 0 ; i < obj.size ; i++) {
            newQueue.q[size + i] = obj.q[i];
        }

        return newQueue;
    }
}

template <typename T, int capacity>
void Queue<T, capacity>::operator+=(const T& value) {
    insert(value);
}

template <typename T, int capacity>
Queue<T, capacity>& Queue<T, capacity>::operator--() {
    remove();
    return *this;
}

template <typename T, int capacity>
Queue<T, capacity> Queue<T, capacity>::operator--(T) {
    Queue<T, capacity> copy(*this);
    remove();
    return copy;
}

template <typename T, int capacity>
bool Queue<T, capacity>::operator==(const Queue& obj) {
    if (size != obj.size || maxSize != obj.maxSize) {
        return false;
    }

    for (int i = 0 ; i < size ; i++) {
        if (q[i] != obj.q[i]) {
            return false;
        }
    }

    return true;
}

template <typename T, int capacity>
bool Queue<T, capacity>::operator!=(const Queue& obj) {
    return !operator==(obj);
}

template <typename T, int capacity>
void Queue<T, capacity>::expand() {
    maxSize = maxSize * 2;

    T* temp = new T[maxSize];

    for (int i = 0 ; i < size ; i++) {
        temp[i] = q[i];
    }

    delete[] q;
    q = temp;
}

#endif