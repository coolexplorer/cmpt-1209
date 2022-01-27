#include <iostream>

using namespace std;

int main() {
    const int a = 10;
    const int *p = &a;

    /*
    a++;

    cout << a << endl;
    cout << b << endl;
    cout << *p << endl;
    */

    char ch = 'a';

    cout << "The ASCII code of the character " << ch << " is: " << (int)ch << endl;

    int* temp = new int[3];
    temp[0] = 1;
    temp[1] = 1;
    temp[2] = 1;

    delete[] temp;

    cout << *temp << endl;

    return 0;
}