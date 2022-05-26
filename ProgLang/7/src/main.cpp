#include "Set.h"
#include "iostream"

int main() {
    std::cout << "set1 -> ";
    Set<int> set1;
    set1.append(1);
    set1.append(2);
    set1.append(3);
    set1.print();

    std::cout << "set2 -> ";
    Set<int> set2(4, 3, 4, 5, 6);
    set2.print();

    std::cout << "set3 -> ";
    auto set3 = set1 + set2;
    set3.print();

    std::cout << "\nset3 <= set2: " << std::boolalpha << (set3 <= set2);
    std::cout << "\nset2 <= set3: " << std::boolalpha << (set2 <= set3);
}
