#include <iostream>

using namespace std;

void printReverse(const int list[], int size) {
    if (size > 0) {
        cout << list[size - 1] << endl;
        printReverse(list, size - 1);
    }
}

int main() {
    int inputList[10];
    
    cout << "Enter 10 intergers: " << endl;
    
    for (int i=0 ; i < 10 ; i++) {
        cin >> inputList[i];
    }

    cout << " The integers in the reverse order are : " << endl;
    printReverse(inputList, 10);
}