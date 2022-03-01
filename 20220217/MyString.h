#include <iostream>
#include <stdexcept>
using namespace std;

class MyString {
public:
    MyString();
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();

    MyString& operator=(const MyString& obj);
    char& operator[](int);
    
    //friend class X;
    //friend X::... 
    friend ostream& operator<<(ostream&, const MyString&);
private:
    char* s;
    int size;
};

MyString::MyString() {
    s = nullptr;
    size = 0;
}

MyString::MyString(const char* str) {
    int len = strlen(str);

    if (len == 0) {
        s = nullptr;
        size = 0;
    } else {
        s = new char[len];
        size = len;

        for (int i=0 ; i < len ; i++) {
            s[i] = str[i];
        }
    }
}

MyString::MyString(const MyString& obj) {
    size = obj.size;

    if (obj.s == nullptr) {
        s = nullptr;
    } else {
        s = new char[size];
        for (int i=0 ; i<size ; i++) {
            s[i] = obj.s[i];
        }
    }
}

MyString::~MyString() {
    delete[] s;
}

MyString& MyString::operator=(const MyString& obj) {
    if (this == &obj) {
        return *this;
    }

    size = obj.size;
    delete[] s;

    if (obj.s == nullptr) {
        s = nullptr;
    } else {
        s = new char[size];
        for (int i = 0 ; i < size ; i++) {
            s[i] = obj.s[i];
        }
    }

    return *this;
}

char& MyString::operator[](int index) {
    if (index < 0 || index >= size) {
        throw runtime_error("Index out of range.");
    }

    return s[index];
}

ostream& operator<<(ostream& out, const MyString& obj) {
    for (int i=0 ; i < obj.size ; i++) {
        out << obj.s[i];
    }

    return out;
}

int main() {
    int a = 10, b = 5, c = 0;
    a = b = c;
    return 0;
}