#include <iostream>
#include <cstring>

using namespace std;

void reverse(char a[], int size);
void pointer();

int main() {
    char x[] = "abc";
    reverse(x, 3);
    cout << x << endl;

    pointer();
    return 0;
}

void reverse(char a[]) {
    reverse(a, strlen(a));
}

void reverse(char a[], int size) {
    if (size >= 2) {
        char temp = a[0];
        a[0] = a[size-1];
        a[size-1] = temp;
        reverse(a+1, size-2);
    }
}

void pointer() {
    int x[] = {1, 2, 3, 4, 5};
    int* p1 = &x[1];
    int* p2 = &x[4];

    cout << p2 - p1 << endl;
    cout << p1 - p2 << endl;
    cout << *(p1+2) << endl;
    cout << p2[-1] << endl;

}

void constData() {
    int y = 52;
    const int *p1 = &y;
    int* const p2 = &y;

    *(p1)++;    // compile error because of const
    p2++;       // cannot change because of const
}