#include <iostream>
using namespace std;

class Unit {
public:
    Unit() {
        cout << "Unit created\n";
    }

    ~Unit() {
        cout << "Unit destroyed\n";
    }
};


int main() {
    try {
        Unit unit;
        throw runtime_error("SOME ERROR!");
    } catch (runtime_error& re) {
        cerr << re.what();
    }
}