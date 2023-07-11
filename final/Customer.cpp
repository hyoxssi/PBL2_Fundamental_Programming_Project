#include "Customer.h"

Customer::Customer(string name, string phone, string email, string password): Human(name, phone, email), password(password) {}

Customer::Customer(const Customer &c): Human(c), password(c.password) {}

Customer::~Customer() {}

void Customer::setPass(string password) {
    this->password = password;
}

istream &operator >> (istream &in, Customer &c) {
    //...
    return in;
}

ostream &operator << (ostream &out, const Customer &c) {
    out << setw(30) << left << c.name << setw(20) << left << c.phone << setw(35) << left << c.email << setw(30) << left << c.password;
    return out;
}