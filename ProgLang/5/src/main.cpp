#include "listfunctions.cpp"
#include "Money.h"
#include "Vector.h"
#include "pqfunctions.cpp"
#include "queue"


int main() {
//    list<double> values{1.0, 2.0, 6.0, 4.0, 5.0};
//    print(values);
//    replaceElement(values, 6.0, 3.0);
//    print(values);
//    deleteElement(values, 2.0);
//    print(values);
//    subDiff(values);
//    print(values);
//
//    list<Money> wallet{Money(53.31, "BYN"), Money(15, "USD"), Money(398.09, "RUB")};
//    print(wallet);
//    replaceElement(wallet, Money(15, "USD"), Money(30, "USD"));
//    print(wallet);
//    deleteElement(wallet, wallet.back());
//    print(wallet);
//    subDiff(wallet);
//    print(wallet);
//
//    Vector<int> numbers = {2, 4, 3, 6, 8};
//    numbers.print();
//    numbers[4] = numbers[2];
//    numbers.print();
//    numbers.pop(2);
//    numbers.print();
//    numbers.subDiff();
//    numbers.print();

    priority_queue<int> pq;
    vector<int> data{3, 5, 1, 4, 6, 2, 10};
    for (auto el: data) pq.push(el);
    print(pq);
    pq = replaceElement(pq, 4, 8);
    print(pq);
    deleteElement(pq, 3);
    print(pq);
    subDiff(pq);
    print(pq);
}
