#include "Date.cpp"

#ifndef Showtimes_h
#define Showtimes_h

class Showtimes {
    private:
        // string nameOfTheMovie;
        int NOD; // number of date
        Date *AOD; // array of date
    public:
        Showtimes(/*string = "UnknownMovie",*/ int = 6);
        Showtimes(const Showtimes &s);
        ~Showtimes();
        void setAOT(int index, string quantity, string time);
        void dis();
        friend ostream &operator << (ostream &out, const Showtimes &s);
};

#endif