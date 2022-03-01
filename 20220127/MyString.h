#ifndef MY_STRING_H
#define MY_STRING_H

class MyString {
public:
    MyString();
    MyString(const char[]);

    // Copy constructor
    // You should pass the reference variable of object when you create the copy contructor
    MyString(const MyString&);
    
    ~MyString();

    // Copy contructor is created automatically by the compiler. 
    // Memberwise Assginment : Will assgin based on the attribute type and name;
    
    int getSize() const;
    static int getCount();
    void concat(const char[]);
private:
    void expand();

    // Instatnce attribute
    // Non-static attribute
    char* s;
    int capacity;
    int size;
    static int count;
};

#endif