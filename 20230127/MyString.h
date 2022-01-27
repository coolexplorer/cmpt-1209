#ifndef MY_STRING_H
#define MY_STRING_H

class MyString {
public:
    MyString();
    MyString(const char[]);
    MyString(const MyString&);
    
    ~MyString();

    // Copy contructor is created automatically by the compiler. 
    // Memberwise Assginment : Will assgin based on the attribute type and name;
    
    int getSize() const;
    void concat(const char[]);
private:
    void expand();

    char* s;
    int capacity;
    int size;
};

#endif