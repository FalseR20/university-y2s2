#include <list>
#include <iostream>

using namespace std;

template<class T>
void print(const list<T> &values) {
    for (auto el: values) {
        cout << el << " ";
    }
    cout << "\n";
}

template<class T>
int replaceElement(list<T> &values, const T &oldValue, const T &newValue) {
    for(auto iter = values.begin(); iter != values.end(); iter++) {
        if (*iter == oldValue) {
            *iter = newValue;
            return 0;
        }
    }
    return -1;
}

template<class T>
int deleteElement(list<T> &values, const T &oldValue) {
    for(auto iter = values.begin(); iter != values.end(); iter++) {
        if (*iter == oldValue) {
            values.erase(iter);
            return 0;
        }
    }
    return -1;
}

template<class T>
void subDiff(list<T> &values) {
    if (values.empty()) return;
    auto iter = values.begin();
    auto minValue = *iter, maxValue = *iter;
    for (iter++; iter != values.end(); iter++) {
        minValue = min(minValue, *iter);
        maxValue = max(maxValue, *iter);
    }
    auto diff = maxValue - minValue;
    for (iter = values.begin(); iter != values.end(); iter++)
        *iter -= diff;
}
