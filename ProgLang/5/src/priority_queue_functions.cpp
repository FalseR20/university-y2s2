#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
void print(priority_queue<T> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

template<class T>
vector<T> &priorityQueueToVector(priority_queue<T> pq) {
    auto vec = new vector<T>;
    while (!pq.empty()) {
        vec->push_back(pq.top());
        pq.pop();
    }
    return *vec;
}

template<class T>
priority_queue<T> &vectorToPriorityQueue(vector<T> vector) {
    auto pq = new priority_queue<T>;
    while (!vector.empty()) {
        pq->push(vector.back());
        vector.pop_back();
    }
    return *pq;
}


template<class T>
priority_queue<T> &replaceElement(priority_queue<T> &pq, const T &oldValue, const T &newValue) {
    auto vector = priorityQueueToVector(pq);
    for (auto iter = vector.begin(); iter != vector.end(); iter++) {
        if (*iter == oldValue) {
            *iter = newValue;
            break;
        }
    }
    auto pq2 = new priority_queue<T>;
    for (auto el:vector)
        pq2->push(el);
    return *pq2;
}

template<class T>
void deleteElement(priority_queue<T> &pq, const T &oldValue) {
    vector<T> vector;
    while (pq.top() != oldValue && !pq.empty()) {
        vector.push_back(pq.top());
        pq.pop();
    }
    pq.pop();
    while (!vector.empty()) {
        pq.push(vector.back());
        vector.pop_back();
    }
}

template<class T>
void subDiff(priority_queue<T> &pq) {
    auto vector = priorityQueueToVector(pq);
    if (vector.empty()) return;
    auto iter = vector.begin();
    auto minValue = *iter, maxValue = *iter;
    for (iter++; iter != vector.end(); iter++) {
        minValue = min(minValue, *iter);
        maxValue = max(maxValue, *iter);
    }
    auto diff = maxValue - minValue;
    for (iter = vector.begin(); iter != vector.end(); iter++)
        *iter -= diff;
    pq = vectorToPriorityQueue(vector);
}
