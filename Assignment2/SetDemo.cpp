#include <iostream>
#include "MySet.h"
using namespace std;

int main() {
    /*
    int arr1[20];
    int arr2[20];
    int size1 = 0, size2 = 0;

    cout << "Set 1 Element size (0-20): ";
    cin >> size1;

    cout << "Please input elements : ";
    for (int i = 0 ; i < size1 ; i++) {
        cin >> arr1[i];
    }

    cout << "Set 2 Element size (0-20): ";
    cin >> size2;

    cout << "Please input elements : ";
    for (int i = 0 ; i < size2 ; i++) {
        cin >> arr2[i];
    }
    */
    
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 6, 7, 8, 5, 10 };
    int size1 = 5, size2 = 5;

    MySet set1 = MySet(arr1, size1);
    MySet set2 = MySet(arr2, size2);

    set1.print();
    set2.print();

    set1.remove(1);
    set2.add(6);
    set2.add(9);

    for (int i = 0 ; i < 10 ; i++) {
        set1.add(i + 10);
    }

    set1.print();
    set2.print();

    MySet intersectionSet = set1.intersectWith(set2);
    MySet unionSet = set1.unionWith(set2);

    intersectionSet.print();
    unionSet.print();

    return 0;
}