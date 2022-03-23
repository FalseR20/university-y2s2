#ifndef INC_1_PRODUCT_H
#define INC_1_PRODUCT_H


class Product {
public:
    Product();
    Product(const char *name, int count, float price);
    Product(Product &product);
    ~Product();

    char* getName();
    int getCount();
    float getPrice();

    void setName(char* name);
    void setCount(int count);
    void setPrice(float price);

protected:
    char *name;
    int count;
    float price;
};


#endif //INC_1_PRODUCT_H
