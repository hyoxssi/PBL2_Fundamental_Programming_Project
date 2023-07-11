#include "LinkedList.cpp"

#ifndef Time_h
#define Time_h

class Time {
    private:
        int hour;
        int minute;
    public:
        Time(int = 0, int = 0);
        Time(const Time &t);
        ~Time();
        void stoTime(string time);
        friend ostream &operator << (ostream &out, const Time &t);
};

#endif