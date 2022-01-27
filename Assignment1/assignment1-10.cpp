#include <iostream>
using namespace std;

void copyArray(const int source[], const int size, int* &arr1, int &len1, int* &arr2, int &len2);

int main() {
    int source[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len1 = 0, len2 = 0;
    int* arr1 = nullptr;
    int* arr2 = nullptr;


    copyArray(source, 9, arr1, len1, arr2, len2);

    cout << "arr1 : ";
    for (int i = 0 ; i < len1 ; ++i) {
        cout << arr1[i] << ' ';
    }

    cout << "\narr2 : ";
    for (int j = 0 ; j < len2 ; ++j) {
        cout << arr2[j] << ' ';
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}

void copyArray(const int source[], const int size, int* &arr1, int &len1, int* &arr2, int &len2) {
    len1 = size / 2;
    len2 = size - len1;

    int* temp1 = new int[len1];
    int* temp2 = new int[len2];

    for (int i = 0 ; i < size ; ++i) {
        if (i < len1)
            temp1[i] = source[i];
        else 
            temp2[i - len1] = source[i];
    }

    arr1 = temp1;
    arr2 = temp2;
}