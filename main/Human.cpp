#include "Human.h"

Human::Human(string name, string phone, string email): name(name), phone(phone), email(email) {}

Human::Human(const Human &h): name(h.name), phone(h.phone), email(h.email) {}

Human::~Human() {}

void Human::setName(string name) {
    this->name = name;
}

void Human::setPhone(string phone) {
    this->phone = phone;
}

void Human::setEmail(string email) {
    this->email = email;
}