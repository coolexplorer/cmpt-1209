#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    double a = 1.0;
    double b = static_cast<float>(5) * 2.5;
    double c = 1;
    double d = static_cast<int>(5) * 2.5F;
    double e = 1E-5;
    double f = 0x1f;
    double g = 2.5F;
    double h = 'A' + 2.5;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;
    cout << h << endl;
}