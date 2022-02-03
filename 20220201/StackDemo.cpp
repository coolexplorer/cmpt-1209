#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<int> intStack;

    cout << "Push 1, 2, 3, andn 4 into Stack" << endl;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);

    cout << "Get size : " << intStack.getSize() << endl;
    cout << "Peek() : " << intStack.peek() << endl;
    cout << "Pop() : " << intStack.pop() << endl;
    cout << "Get size : " << intStack.getSize() << endl;

    cout << "Is empty : " << intStack.empty() << endl;



    return 0;
}