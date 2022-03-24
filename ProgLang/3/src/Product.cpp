#include <cstring>
#include <cstdio>

#include "Product.h"


Product::Product() : count_(0), price_(0) {
    name_ = new char[8];
    strcpy(name_, "Unnamed");
    printf("LOG: Product \"%s\" created (without parameters)\n", name_);
}

Product::Product(const char *name, int count, float price) : count_(count), price_(price) {
    name_ = new char[strlen(name)];
    strcpy(name_, name);
    printf("LOG: Product \"%s\" created (with parameters)\n", name_);
}

Product::Product(const Product &product) : count_(product.count_), price_(product.price_) {
    name_ = new char[strlen(product.name_)];
    strcpy(name_, product.name_);
    printf("LOG: Product \"%s\" created (by coping)\n", name_);
}

Product::~Product() {
    printf("LOG: Product \"%s\" deleted\n", name_);
    delete[] name_;
}

void Product::print() const {
    printf("LOG: Product \"%s\": count = %d, price = %.2f\n", name_, count_, price_);
}

char *Product::getName() const {
    auto name = new char[strlen(name_)];
    strcpy(name, name_);
    return name;
}

int Product::getCount() const {
    return count_;
}

float Product::getPrice() const {
    return price_;
}

void Product::setName(const char *name) {
    printf("LOG: Product \"%s\": changed name (%s -> %s)\n", name_, name_, name);
    delete[] name_;
    name_ = new char[strlen(name)];
    strcpy(name_, name);
}

void Product::setCount(int count) {
    printf("LOG: Product \"%s\": changed count (%d -> %d)\n", name_, count_, count);
    count_ = count;
}

void Product::setPrice(float price) {
    printf("LOG: Product \"%s\": changed price (%.2f -> %.2f)\n", name_, price_, price);
    price_ = price;
}
