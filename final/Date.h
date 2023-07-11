#include "Time.cpp"

#ifndef Date_h
#define Date_h

class Date {
    private:
        int DOW; // day of the week
        int day;
        int month;
        int year;
        int NOT; // number of time
        Time *AOT; //array of time
    public:
        Date(int = 0, int = 0, int = 0, int = 0);
        Date(const Date &d);
        ~Date();
        void setAOT(string quantity, string time);
        // void displayAOT();
        friend istream &operator >> (istream &in, Date &d);
        friend ostream &operator << (ostream &out, const Date &d);
        Date &operator ++ ();
        void displayTime();
};

#endif