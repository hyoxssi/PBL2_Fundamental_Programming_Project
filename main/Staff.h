#include "Customer.cpp"

#ifndef Staff_h
#define Staff_h

class Staff: public Human {
    private:
        string code;
    public:
        Staff(string = "UnknownName", string = "UnknownContact", string = "UnknownEmail", string = "UnknownCode");
        Staff(const Staff &s);
        ~Staff();
        void setCode(string code);
        friend istream &operator >> (istream &in, Staff &s);
        friend ostream &operator << (ostream &out, const Staff &s);
};

#endif