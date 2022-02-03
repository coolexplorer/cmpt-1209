#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    PriorityQueue<int, 100> queue1;
    queue1.insert(20);
    queue1.insert(30);
    queue1.insert(50);
    queue1.insert(10);
    queue1.insert(50);

    queue1.print();

    queue1.remove();
    queue1.insert(60);

    queue1.print();
    queue1.remove();
    queue1.print();

    int list[10] = { 1, 3, 6, 4, 3, 2, 2, 10, 100, 2 };

    try {
        PriorityQueue<int, 5> queue2(list, 10);
    } catch (runtime_error e) {
        cout << "Exception : " << e.what() << endl;
    }
    
    PriorityQueue<int, 3> queue3;

    try {
        for (int i = 0 ; i < 5 ; i++) {
            queue3.insert(i);
        }
    } catch (runtime_error e) {
        cout << "Exception : " << e.what() << endl;
    }

    PriorityQueue<int, 10> queue4(list, 10);

    try {
        for (int i = 0 ; i < 11 ; i++) {
            queue4.remove();
        }
    } catch (runtime_error e) {
        cout << "Exception : " << e.what() << endl;
    }


    return 0;
}