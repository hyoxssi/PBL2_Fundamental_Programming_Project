#include "Seat.cpp"

#ifndef Cinema_h
#define Cinema_h

class Cinema {
    private:
        int numberOfSeats;
        int numberOfRows;
        int numberOfColumns;
        string name;
        Seat **matrix;
    public:
        Cinema(int = 0, int = 0, string = "UnknownCinema");
        Cinema(const Cinema &c);
        ~Cinema();
        void setThis(int NOR, int NOC, string name);
        void paid(char row, int column, string file);
        void read(string file);
        long getPrice(char row, int column);
        long income();
        friend istream &operator >> (istream &in, Cinema &c);
        friend ostream &operator << (ostream &out, const Cinema &c);
};

#endif