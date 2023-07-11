#include "Human.cpp"

#ifndef Customer_h
#define Customer_h

class Customer: public Human {
    private:
        string password;
    public:
        Customer(string = "UnknownName", string = "UnknownContact", string = "UnknownEmail", string = "UnknownPass");
        Customer(const Customer &c);
        ~Customer();
        void setPass(string password);
        friend istream &operator >> (istream &in, Customer &c);
        friend ostream &operator << (ostream &out, const Customer &c);
};

#endif