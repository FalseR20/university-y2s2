#include "list_functions.cpp"
#include "Money.h"
#include "Vector.h"
#include "priority_queue_functions.cpp"


int main() {
    cout << "Task 1\n";
    list<double> values{1.0, 2.5, 5.0, 7.5, 10.0};
    print(values);
    replaceElement(values, 1.0, 1.5);
    print(values);
    deleteElement(values, 5.0);
    print(values);
    subDiff(values);
    print(values);

    cout << "\nTask 2\n";
    list<Money> wallet{Money(53.31, "BYN"), Money(15, "USD"), Money(398.09, "RUB")};
    print(wallet);
    replaceElement(wallet, Money(15, "USD"), Money(30, "USD"));
    print(wallet);
    deleteElement(wallet, wallet.back());
    print(wallet);
    subDiff(wallet);
    print(wallet);

    cout << "\nTask 3\n";
    Vector<int> numbers = {2, 4, 3, 6, 8};
    numbers.print();
    numbers[4] = numbers[2];
    numbers.print();
    numbers.pop(2);
    numbers.print();
    numbers.subDiff();
    numbers.print();

    cout << "\nTask 4\n";
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

    cout << "\nTask 5\n";
    priority_queue<int, vector<int>> pq2;
    vector<int> data2{5, 6, 4, 7, 3, 8, 2, 9};
    for (auto el: data2) pq2.push(el);
    print(pq2);
    pq2 = replaceElement(pq2, 4, 8);
    print(pq2);
    deleteElement(pq2, 3);
    print(pq2);
    subDiff(pq2);
    print(pq2);
}
