#ifndef PRODUCT_H
#define PRODUCT_H


class Product {
public:
    Product();
    Product(const char *name, int count, float price);
    Product(const Product &product);
    ~Product();

    void print() const;

    char* getName() const;
    int getCount() const;
    float getPrice() const;

    void setName(const char* name);
    void setCount(int count);
    void setPrice(float price);

protected:
    char *name_;
    int count_;
    float price_;
};


#endif //PRODUCT_H
