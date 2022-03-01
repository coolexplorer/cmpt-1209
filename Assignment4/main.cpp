#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int, 10> q1;
    q1.insert(10);
    q1.insert(20);
    q1.insert(30);
    q1.insert(40);
    q1.remove();

    Queue<int, 10> q2(q1);
    q2 += 40;
    --q1;
    q1--;

    q1 += 100;
    q1.print();
    q2.print();

    if (q1 == q2) {
        cout << "Same" << endl;
    } else if (q1 != q2) {
        cout << "Different" << endl;
    }

    q1 = q2;
    q1.print();

    if (q1 == q2) {
        cout << "Same" << endl;
    } else if (q1 != q2) {
        cout << "Different" << endl;
    }

    q1 = q1 + q2;
    q1.print();

    cout << "Print q2" << endl;

    q2.remove();
    --q2;

    cout << q2 << endl;
    cout << q1 + q2 << endl;

    Queue<int, 10> q3;
    q3 = Queue<int, 10>(q1+q2);

    cout << q3;

    return 0;
}