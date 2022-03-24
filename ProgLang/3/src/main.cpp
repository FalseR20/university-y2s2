#include <cstdio>
#include <cstring>

#include "Product.h"

int main() {
    auto empty = new Product;
    delete empty;

    auto beerPtr = new Product("Ideal", 35, 1.29 /* from groshik */ );
    Product beerCopy(*beerPtr);
    delete beerPtr;
    beerCopy.setName(strcat(beerCopy.getName(), " NEW!!!"));
    beerCopy.setPrice(beerCopy.getPrice() * 1.45f);

    Product chips("Lay's: Chili & lime", 10, 2.39);
    chips.setCount(15);

    float starterPack = chips.getPrice() + beerCopy.getPrice();
    printf("The minimum price = %.2f\n", starterPack);

    void (Product::*printPtr)() const;
    printPtr = &Product::print;
    (beerCopy.*printPtr)();
}
