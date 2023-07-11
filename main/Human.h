#include "Movie.cpp"

#ifndef Human_h
#define Human_h

class Human {
    protected:
        string name;
        string phone;
        string email;
    public:
        Human(string = "UnknownName", string = "UnknownContact", string = "UnknownEmail");
        Human(const Human &h);
        ~Human();
        void setName(string name);
        void setPhone(string phone);
        void setEmail(string email);
};

#endif