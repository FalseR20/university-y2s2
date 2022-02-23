#include <iostream>
#include <cmath>

using namespace std;

// Template function
template<typename T>
T func(T a, T b) {
    T x = pow(a + b, 4);
    T y = pow(a, 4) + 4 * pow(a, 3) * b;
    T z = 6 * pow(a, 2) * pow(b, 2) + 4 * a * pow(b, 3) + pow(b, 4);
    return (x - y) / z;
}


int main() {
    float floatA = 100, floatB = 0.001;
    double doubleA = 100, doubleB = 0.001;
    cout << "TASK 1\n";
    cout << "func(floatA, floatB) = " << func(floatA, floatB) << '\n';
    cout << "func(doubleA, doubleB) = " << func(doubleA, doubleB) << '\n';

    cout << "\nTASK 2\n";
    double m, n;
    cout << "print m:";
    cin >> m;
    cout << "print n:";
    cin >> n;
    cout << "(++n*++m) = " << (++n * ++m);
    cout << "\n(m++<n) = " << (m++ < n);
    cout << "\n(n++>m) = " << (n++ > m);
}
