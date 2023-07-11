#include "Date.h"

Date::Date(int day, int month, int year, int NOT): day(day), month(month), year(year), DOW((day + 2* month + (3 * (month + 1)) / 5 + year + (year / 4)) % 7), NOT(NOT), AOT(new Time [NOT]) {
    Time temp;
    for (int i = 0; i < NOT; ++i) {
        AOT[i] = temp;
    }
}

Date::Date(const Date &d): day(d.day), month(month), year(year), DOW(d.DOW), NOT(d.NOT), AOT(new Time [NOT]) {
    for (int i = 0; i < NOT; ++i) {
        AOT[i] = d.AOT[i];
    }
}

Date::~Date() {
    delete [] AOT;
}

void Date::setAOT(string quantity, string time) {
    int i = 0;
    this->NOT = stoi(quantity);
    this->AOT = new Time [NOT];
    string word = "";
    for (auto x : time) {
        if (x == ',') {
            AOT[i++].stoTime(word);
            word = ""; 
        }
        else {
            word = word + x;
        }
    }
    AOT[i].stoTime(word);
}

// void Date::displayAOT() {
//     for (int i = 0; i < this->NOT; ++i) {
//         cout << AOT[i] << "                   ";
//     }
// }

istream &operator >> (istream &in, Date &d) {
    string date;
    in >> date;
    d.day = stoi(date.substr(0,2));
    d.month = stoi(date.substr(3,2));
    d.year = stoi(date.substr(6));
    d.DOW = (d.day + 2* d.month + (3 * (d.month + 1)) / 5 + d.year + (d.year / 4)) % 7;
    return in;
}

ostream &operator << (ostream &out, const Date &d) {
    if (d.DOW == 0) {
        if (d.day < 10) {
            if (d.month < 10) {
                out << "Chu nhat, ngay 0" << d.day << "/0" << d.month << "/" << d.year;
            }
            else {
                out << "Chu nhat, ngay 0" << d.day << "/" << d.month << "/" << d.year;
            }
        }
        else {
            if (d.month < 10) {
                out  << "Chu nhat, ngay " << d.day << "/0" << d.month << "/" << d.year;
            }
            else {
                out  << "Chu nhat, ngay " << d.day << "/" << d.month << "/" << d.year;
            }
        }
    }
    else {
        if (d.day < 10) {
            if (d.month < 10) {
                out << "Thu " << d.DOW + 1 << ", ngay 0" << d.day << "/0" << d.month << "/" << d.year;
            }
            else {
                out << "Thu " << d.DOW + 1 << ", ngay 0" << d.day << "/" << d.month << "/" << d.year;
            }
        }
        else {
            if (d.month < 10) {
                out  << "Thu " << d.DOW + 1 << ", ngay " << d.day << "/0" << d.month << "/" << d.year;
            }
            else {
                out  << "Thu " << d.DOW + 1 << ", ngay " << d.day << "/" << d.month << "/" << d.year;
            }
        }
    }
    return out;
}

int DOM(int month, int year) { // days of month
    int DOM[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        DOM[2] = 29;
    return DOM[month];
}

Date &Date::operator ++ () {
    if (this->day < DOM(this->month, this->year)) ++this->day;
    else {
        this->day = 1;
        if (this->month < 12) ++this->month;
        else {
            this->month = 1;
            ++this->year;
        }
    }
    if (this->DOW == 6) this->DOW = 0;
    else ++this->DOW;
    return *this;
}

void Date::displayTime() {
    for (int i = 0; i < NOT; ++i) {
        cout << i + 1 << ". " << AOT[i];
    }
}