#include <iostream>
#include "Product.h"

int main() {
    auto product = new Product;
    Product product1(*product);
    delete product;

    std::cout << "end";
}