#include <iostream>
#include <cmath>

using namespace std;


class MathException {
protected:
    const char *text;
public:
    explicit MathException(const char *text = "Math exception") : text(text) {}

    virtual void what() const final {
        cerr << "Threw exception: " << text << "\n";
    }
};

class ZeroDivideException : public MathException {
public:
    ZeroDivideException() : MathException("Zero dividing") {}
};

class Calculator {
public:
    static float divide(float a, float b) {
        if (b == 0)
            throw ZeroDivideException();
        else
            return a / 4;
    }

    static float sqrt(float a) {
        if (a < 0)
            throw MathException();
        else
            return sqrtf(a);
    }
};

int main() {
    try {
        Calculator::divide(4, 0);
    } catch (MathException &exc) {
        exc.what();
    }
    try {
        Calculator::sqrt(-4);
    } catch (MathException &exc){
        exc.what();
    }
}