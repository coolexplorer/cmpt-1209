#include <iostream>
#include "MySet.h"
using namespace std;

int main() {
    int arr1[20];
    int arr2[20];
    int size1 = 0, size2 = 0;

    // Input the first set 
    cout << "Set 1 Element size (0-20): ";
    cin >> size1;

    if (size1 > 20) {
        size1 = 20;
    }
    cin.ignore(256, '\n');

    cout << "Please input elements : ";
    for (int i = 0 ; i < size1 ; i++) {
        cin >> arr1[i];
    }
    cin.ignore(256, '\n');

    // Input the second set
    cout << "Set 2 Element size (0-20): ";
    cin >> size2;

    if (size2 > 20) {
        size2 = 20;
    }
    cin.ignore(256, '\n');

    cout << "Please input elements : ";
    for (int i = 0 ; i < size2 ; i++) {
        cin >> arr2[i];
    }
    cin.ignore(256, '\n');

    MySet set1 = MySet(arr1, size1);
    MySet set2 = MySet(arr2, size2);

    cout << "\n[ Set 1 ]" << endl;
    set1.print();
    cout << "[ Set 2 ]" << endl;
    set2.print();

    MySet intersectionSet = set1.intersectWith(set2);
    MySet unionSet = set1.unionWith(set2);

    cout << "\n[ Intersection Set ]" << endl;
    intersectionSet.print();

    cout << "\n[ Union Set ]" << endl;
    unionSet.print();

    // Extra test
    cout << "\n[ Extra Tests ]" << endl;
    cout << "Remove 1 from Set1" << endl;
    set1.remove(1);
    cout << "Add 6 into Set2" << endl;
    set2.add(6);
    cout << "Add 9 into Set2" << endl;
    set2.add(9);

    cout << "Add 10 to 19 into Set 1" << endl;
    for (int i = 0 ; i < 10 ; i++) {
        set1.add(i + 10);
    }

    cout << "[ Set 1 ]" << endl;
    set1.print();
    cout << "[ Set 2 ]" << endl;
    set2.print();

    return 0;
}