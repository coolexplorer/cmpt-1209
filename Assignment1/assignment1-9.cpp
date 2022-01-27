#include <iostream>
using namespace std;

void swap(int* list1, int* list2, int n) {
    if (n < 1) {
        return;
    } else {
        int temp = list1[0];
        list1[0] = list2[0];
        list2[0] = temp;
        swap(list1 + 1, list2 + 1, n - 1);
    }
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    swap(a, b, 10);

    for (int i = 0 ; i < 10 ; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;

    for (int i = 0 ; i < 10 ; ++i) {
        cout << b[i] << ' ';
    
    cout << endl;

    return 0;
}