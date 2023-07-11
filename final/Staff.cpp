#include "Staff.h"

Staff::Staff(string name, string phone, string email, string code): Human(name, phone, email), code(code) {}

Staff::Staff(const Staff &s): Human(s), code(s.code) {}

Staff::~Staff() {}

void Staff::setCode(string code) {
    this->code = code;
}

istream &operator >> (istream &in, Staff &s) {
    //...
    return in;
}

ostream &operator << (ostream &out, const Staff &s) {
    out << setw(30) << left << s.code << setw(30) << left << s.name << setw(20) << left << s.phone << setw(35) << left << s.email << endl;
    return out;
}