#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
T maxValue(const T& value1, const T& value2) {
    if (value1 > value2) {
        return value1;
    } else {
        return value2;
    }
}

int main() {
    cout << "Maximum between 1 and 3 is " << maxValue<double>(1, 3) << endl;
    cout << "Maximum between 1.5 and 0.3 is " << maxValue(1.5, 0.3) << endl;

    return 0;
}