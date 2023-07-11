#include "Time.h"

Time::Time(int hour, int minute): hour(hour), minute(minute) {}

Time::Time(const Time &t): hour(t.hour), minute(t.minute) {}

Time::~Time() {}

ostream &operator << (ostream &out, const Time &t) {
    if (t.hour < 10) {
        if (t.minute < 10) {
            out << "0" << t.hour << ":0" << t.minute << endl;
        }
        else {
            out << "0" << t.hour << ":" << t.minute << endl;
        }
    }
    else {
        if (t.minute < 10) {
            out << t.hour << ":0" << t.minute << endl;
        }
        else {
            out << t.hour << ":" << t.minute << endl;
        }
    }
    return out;
}

void Time::stoTime(string time) {
    int pos = time.find(":");
    string sub = time.substr(0 , pos);
    this->hour = stoi(sub);
    sub = time.substr(pos + 1);
    this->minute = stoi(sub);
}

// istream &operator >> (istream &in, Time &t) {
    // ...
    // return in;
// }

// Time &Time::operator ++ () {
//     //...
//     return *this;
// }