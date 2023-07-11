#include "Staff.cpp"

#ifndef Seat_h
#define Seat_h

class Seat {
    private:
        char row;
        int column;
        bool status;
        long price;
    public:
        Seat(char = '?', int = 0, bool = 0);
        Seat(const Seat &s);
        ~Seat();
        bool getStatus();
        void setStatus(bool status);
        char getRow();
        void setRow(const char row);
        int getColumn();
        void setColumn(const int column);
        long getPrice();
        void setPrice(const long price);
        friend istream &operator >> (istream &in, Seat &s);
        friend ostream &operator << (ostream &out, const Seat &s);
};

#endif