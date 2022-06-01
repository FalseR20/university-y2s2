#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>

using namespace std;


template<class T>
class Vector {
    vector<T> _vector;
public:
    Vector() {}

    Vector(Vector &v) : _vector(v._vector) {}

    Vector(initializer_list<T> v) : _vector(v) {}

    void print() {
        for (auto el: _vector) {
            cout << el << " ";
        }
        cout << "\n";
    }

    T &operator[](unsigned index) {
        return _vector[index];
    }

    T &pop(unsigned index) {
        auto el = new T(_vector.at(index));
        _vector.erase(_vector.begin() + index);
        return *el;
    }

    void subDiff() {
        if (_vector.empty()) return;
        auto iter = _vector.begin();
        auto minValue = *iter, maxValue = *iter;
        for (iter++; iter != _vector.end(); iter++) {
            minValue = min(minValue, *iter);
            maxValue = max(maxValue, *iter);
        }
        auto diff = maxValue - minValue;
        for (iter = _vector.begin(); iter != _vector.end(); iter++)
            *iter -= diff;
    }
};


#endif //VECTOR_H
