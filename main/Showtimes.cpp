#include "Showtimes.h"

Showtimes::Showtimes(int NOD): NOD(NOD), AOD(new Date [NOD]) {
    Date today(25, 12, 2022, 0);
    for (int i = 0; i < NOD; ++i) {
        AOD[i] = ++today;
    }
}

Showtimes::Showtimes(const Showtimes &s): NOD(s.NOD), AOD(new Date [NOD]) {
    for (int i = 0; i < NOD; ++i) {
        AOD[i] = s.AOD[i];
    }
}

Showtimes::~Showtimes() {
    delete [] AOD;
}

void Showtimes::setAOT(int index, string quantity, string time) {
    AOD[index].setAOT(quantity, time);
}

void Showtimes::dis() {
    for (int i = 0; i < NOD; ++i) {
        cout << AOD[i];
    }
}

ostream &operator << (ostream &out, const Showtimes &s) {
    for (int i = 0; i < 6; ++i) {
        out << i + 1 << ". " << s.AOD[i] << endl;
        s.AOD[i].displayTime();
        out << endl;
    }
    return out;
}

// int main() {
//     Showtimes s("fkasmndflk", 2, 3);
//     cout << s;
//     return 0;
// }