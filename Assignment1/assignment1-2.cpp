#include <iostream>

using namespace std;

int main() {
    short int x[3] = {1, 2, 3};
    short int y = 8;
    cout << sizeof(x) << endl;
    cout << x << endl;
    cout << x + 8 << endl;
    cout << *(x + 2) << endl;
    cout << *x + 1 << endl;
    cout << x[3] << endl;
}