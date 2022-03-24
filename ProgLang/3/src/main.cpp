#include <cstdio>
#include <cstring>

#include "Product.h"

int main() {
    auto empty = new Product;
    delete empty;

    auto beerPtr = new Product("Ideal", 35, 1.29 /* from groshik*/ );
    Product beerCopy(*beerPtr);
    delete beerPtr;
    beerCopy.setName(strcat(beerCopy.getName(), " NEW!!!"));
    beerCopy.setPrice(beerCopy.getPrice() * 1.45);

    Product chips("Lay's: Chile lemon", 10, 2.39);
    chips.setCount(15);

    float averagePrice = (
            (chips.getPrice() * chips.getCount() + beerCopy.getPrice() * beerCopy.getCount())
            / (chips.getCount() + beerCopy.getCount())
    );
    printf("The average price = %.2f\n", averagePrice);

    void (Product::*printPtr)() const;
    printPtr = &Product::print;
    (beerCopy.*printPtr)();
}