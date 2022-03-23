#include <cstring>
#include "Product.h"

Product::Product() : count(0), price(0) {
    name = new char[8];
    strcpy(name, "Unnamed");
}

Product::Product(const char *name, int count, float price) : count(count), price(price) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

Product::Product(Product &product) : count(product.count), price(product.price) {
    name = new char[strlen(product.name)];
    strcpy(name, product.name);
}

Product::~Product() {
    delete[] name;
}

char *Product::getName() {
    auto buf = new char[strlen(name)];
    strcpy(buf, name);
    return name;
}

int Product::getCount() {
    return 0;
}

float Product::getPrice() {
    return 0;
}

void Product::setName(char *name) {

}

void Product::setCount(int count) {

}

void Product::setPrice(float price) {

}
