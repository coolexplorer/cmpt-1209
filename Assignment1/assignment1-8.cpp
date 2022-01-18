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

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(e).name() << endl;
    cout << typeid(f).name() << endl;
    cout << typeid(g).name() << endl;
    cout << typeid(h).name() << endl;
}