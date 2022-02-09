#include <iostream>
#include <cmath>

template<typename T>
T func(T a, T b) {
    T x = pow(a + b, 4);
    T y = pow(a, 4) + 4 * pow(a, 3) * b;
    T z = 6 * pow(a, 2) * pow(b, 2) + 4 * a * pow(b, 3) + pow(b, 4);
    return (x - y) / z;
}


int main() {
    float fa = 100, fb = 0.001;
    double da = 100, db = 0.001;
    std::cout << func(fa, fb) << '\n' << func(da, db) << '\n';

    double m, n;
    std::cout << "print: m n : ";
    std::cin >> m >> n;
    std::cout << (++n*++m) << '\n'; // ++n * ++m
    std::cout << (m++<n) << '\n'; // m++ < n
    std::cout << (n++>m) << '\n'; // n++ > m
}
