#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <iostream>

using namespace std;

class Money {
    double value;
    string currency;
public:
    Money() : value(0), currency("BYN") {}

    Money(double value, string currency) : value(value), currency(move(currency)) {}

    Money(const Money &money) : value(money.value), currency(move(money.currency)) {}

    Money &operator=(const Money &money) {
        value = money.value;
        currency = move(money.currency);
        return *this;
    }

    bool operator==(const Money &other) const {
        return ((value == other.value) && (currency == other.currency));
    }


    Money &operator-=(Money &other) {
        value -= other.value;
        return *this;
    }

    Money &operator-(const Money &other) const {
        auto money = new Money(*this);
        money->value -= other.value;
        return *money;
    }

    friend ostream &operator<<(ostream &out, const Money &money);

    friend istream &operator>>(istream &in, Money &money);

    friend Money &min(Money &m1, Money &m2);

    friend Money &max(Money &m1, Money &m2);

};

ostream &operator<<(ostream &out, const Money &money) {
//    out << "Money(" << money.currency << " " << money.value << ")";
    out << money.currency << "@" << money.value;
    return out;
}

istream &operator>>(istream &in, Money &money) {
    in >> money.value >> money.currency;
    return in;
}

Money &min(Money &m1, Money &m2) {
    return (m1.value < m2.value) ? m1 : m2;
}

Money &max(Money &m1, Money &m2) {
    return (m1.value > m2.value) ? m1 : m2;
}


#endif //MONEY_H