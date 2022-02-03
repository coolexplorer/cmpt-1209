#include <iostream>
#include "MySet.h"
using namespace std;

MySet::MySet() {
    bufferSize = 10;
    size = 0;
    set = new int[bufferSize];
}

MySet::MySet(const int sequence[], int size) {
    this->bufferSize = 10;
    this->size = 0;

    if (size > bufferSize) {
        bufferSize = size;
    }

    set = new int[bufferSize];

    for (int i = 0 ; i < size ; i++) {
        if (!has(sequence[i])) {
            set[this->size] = sequence[i];
            this->size++;
        }
    }
}

MySet::MySet(const MySet& anotherSet) {
    bufferSize = anotherSet.bufferSize;
    size = anotherSet.size;

    set = new int[bufferSize];

    for (int i = 0 ; i < size ; i++) {
        set[i] = anotherSet.set[i];
    }
}

MySet::~MySet() {
    delete[] set;
}

bool MySet::add(int item) {
    if (size >= bufferSize) {
        expand(1);
    }

    if (!has(item)) {
        set[size] = item;
        size++;
        return true;
    }

    return false;
}

bool MySet::add(const int sequence[], int size) {
    if (this->size + size >= bufferSize) {
        expand(size);
    }

    int index = 0;
    bool isAdded = false;
    while (index < size) {
        if (!has(sequence[index])) {
            add(sequence[index]);
            size++;
            isAdded = true;
        }
        index++;
    }

    return isAdded;
}

bool MySet::remove(int item) {
    int index = 0;

    if (has(item)) {
        for (int i = 0 ; i < size ; i++) {
            if (set[i] != item) {
                index = i;
                break;
            }
        }
        
        set[index] = set[size - 1];
        size--;

        return true;
    } else {
        return false;
    }
}

bool MySet::has(int item) const {
    for (int i = 0 ; i < size ; i++) {
        if (set[i] == item) {
            return true;
        }
    }
    return false;
}

MySet MySet::unionWith(const MySet& anotherSet) const {
    MySet newSet = MySet(set, size);
    
    for (int i = 0 ; i < anotherSet.size ; i++) {
        if (!newSet.has(anotherSet.set[i])) {
            newSet.add(anotherSet.set[i]);
        }
    }

    return newSet;
}

MySet MySet::intersectWith(const MySet& anotherSet) const {
    MySet newSet = MySet();
    const MySet *baseSet;
    const MySet *compareSet;

    if (size < anotherSet.size) {
        baseSet = this;
        compareSet = &anotherSet;
    } else {
        baseSet = &anotherSet;
        compareSet = this;
    }

    for (int i = 0 ; i < baseSet->size ; i++) {
        if (compareSet->has(baseSet->set[i])) {
            newSet.add(baseSet->set[i]);
        }
    }

    return newSet;
}

void MySet::clear() {
    delete[] set;

    MySet();
}

int MySet::getSize() const {
    return size;
}

void MySet::print() const {
    cout << "MySet : [ ";

    for (int i = 0 ; i < size ; i++) {
        cout << set[i] << ' ';
    }

    cout << "], Size: " << size << ", BufferSize: " << bufferSize << endl;
}

void MySet::expand(int expanedSize) {
    int buffer = 0;

    if (expanedSize == 1) {
        buffer = bufferSize / 2;
    } else {
        buffer = expanedSize;
    }

    bufferSize = size + buffer;

    int* temp = new int[size + buffer];

    copyArray(set, temp, size);

    delete[] set;
    set = temp;
}

void MySet::copyArray(const int* src, int* dest, int size) {
    for (int i = 0 ; i < size ; i++) {
        dest[i] = src[i];
    }
}