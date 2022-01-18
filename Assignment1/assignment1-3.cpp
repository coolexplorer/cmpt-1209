#include <iostream>

using namespace std;

int max(const int* list, int size) throw(const int*, int){
     if(list == nullptr)
          throw list;

     if(size <= 0)
          throw size;

     int maxValue = list[0];

     for(int i = 1; i< size; i++)
          if(list[i] > maxValue)
               maxValue = list[i];

     return maxValue;
}

int main() {
    int size = 0;
    int p[] = {1, 3, 5, 6, 23, 5, 6, 3, 2};

    try {
        cout << max(nullptr, size) << endl;
    } catch (const int* list) {
        cout << "The list is not valid";
    } catch (int size) {
        cout << "The list size is not valid";
    }

    return 0;
}
