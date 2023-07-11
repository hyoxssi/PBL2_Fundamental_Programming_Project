#include "Seat.h"

Seat::Seat(char row, int column, bool status): row(row), column(column), status(status) {}

Seat::Seat(const Seat &s): row(s.row), column(s.column), status(s.status) {}

Seat::~Seat() {}

bool Seat::getStatus() {
    return this->status;
}

void Seat::setStatus(bool status) {
    this->status = status;
}

char Seat::getRow() {
    return this->row;
}

void Seat::setRow(const char row) {
    this->row = row;
}

int Seat::getColumn() {
    return this->column;
}

void Seat::setColumn(const int column) {
    this->column = column;
}

long Seat::getPrice() {
    return this->price;
}

void Seat::setPrice(const long price) {
    this->price = price;
}

istream &operator >> (istream &in, Seat &s) {
    cout << "Nhap ky tu hang ghe: "; in >> s.row;
    s.row = toupper(s.row);
    cout << "Nhap so ghe: "; in >> s.column;
    cout << "Nhap trang thai ghe (1 cho da duoc dat truoc, 0 cho con trong): "; in >> s.status;
    return in;
}

ostream &operator << (ostream &out, const Seat &s) {
    out << "Thong tin cua ghe: " << s.row << s.column << ", ";
    if (s.status == 0) out << "ghe van con trong." << endl;
    else out << "ghe da duoc dat truoc." << endl;
    return out;
}