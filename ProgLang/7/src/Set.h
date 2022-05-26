#ifndef SET_H
#define SET_H

#include <iostream>
#include <stdarg.h>


template<class T>
class Set {
    unsigned int count;
    unsigned int countReal;
    T *array;

public:
    Set() : count(0), countReal(0), array(nullptr) {}

    Set(unsigned int n, ...) : count(0), countReal(n), array(new T[countReal]) {
        va_list factor;
        va_start(factor, n);
        T arg;
        for (int i = 0; i < n; i++) {
            arg = va_arg(factor, T);
            if (!in(arg)) {
                array[i] = arg;
                count++;
            }
        }
        va_end(factor);
    }

    Set<T>(const Set<T> &other) : count(other.count), countReal(other.countReal) {
        array = new T[countReal];
        for (int i = 0; i < count; ++i) {
            array[i] = other.array[i];
        }
    }

    bool in(const T t) const {
        for (int i = 0; i < count; ++i)
            if (array[i] == t) return true;
        return false;
    }

    void append(const T t) {
        if (!count) {
            array = new T(t);
            count = countReal = 1;
            return;
        }
        if (in(t)) return;
        if (count != countReal) {
            array[count++] = t;
            return;
        }
        countReal = count * 2;
        auto newSet = new T[countReal];
        for (int i = 0; i < count; ++i) {
            newSet[i] = array[i];
        }
        newSet[count++] = t;
        delete[] array;
        array = newSet;
    }

    void print() const {
        std::cout << "Set(" << count << "/" << countReal << "):";
        for (int i = 0; i < count; ++i) {
            std::cout << " " << array[i];
        }
        std::cout << std::endl;
    }

    Set<T> &operator+=(const Set<T> &other) {
        T t;
        for (int i = 0; i < other.count; ++i) {
            t = other.array[i];
            if (!in(t)) append(t);
        }
        return *this;
    }

    Set<T> &operator+(const Set<T> &other) const {
        auto set = new Set<T>(*this);
        *set += other;
        return *set;
    }

    bool operator<=(const Set<T> &other) const {
        for (int i = 0; i < count; ++i) {
            if (!other.in(array[i])) return false;
        }
        return true;
    }
};

#endif //SET_H
