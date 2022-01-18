#include <iostream>

using namespace std;

int main() {
    int a = 10;
    const int b = a;
    const int *p = &b;

    a++;

    cout << a << endl;
    cout << b << endl;
    cout << *p << endl;

    char ch = 'a';

    cout << "The ASCII code of the character " << ch << " is: " << (int)ch;

    return 0;
}