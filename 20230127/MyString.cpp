#include <cstring>
#include "MyString.h"

MyString::MyString() {
    capacity = 11;
    s = new char[capacity];
    s[0] = '\0';
    size = 0;
}

MyString::MyString(const char s[]) {
    size = strlen(s);
    capacity = size + 1;
    this->s = new char[capacity];

    int i = 0;
    for (i = 0 ; s[i] != '\0' ; i++) {
        this->s[i] = s[i];
    }
    this->s[i] = '\0';
}

MyString::MyString(const MyString& obj2) {
    capacity = obj2.capacity;
    size = obj2.size;

    s = new char[capacity];

    for (int i = 0 ; i <= size ; i++) {
        s[i] = obj2.s[i];
    }
    s[capacity] = '\0';
}

MyString::~MyString() {
    delete[] s;
}

int MyString::getSize() const {
    return size;
}

void MyString::concat(const char s2[]) {
    int size = strlen(s2);
    int newSize = this->size + size;
    
    if (newSize >= capacity) {
        expand();
    }

    for (int i = this->size, j = 0 ; i < newSize ; i++, j++) {
        s[i] = s2[j];
    }

    this->size = newSize;
    s[newSize] = '\0';
}

void MyString::expand() {
    capacity *= 2;
    char* temp = new char[capacity];

    for (int i = 0 ; i <= size ; i++) {
        temp[i] = s[i];
    }

    delete[] s;

    s = temp;
}

