#include "Cinema.cpp"

#ifndef CinemaSystem_h
#define CinemaSystem_h

class CinemaSystem {
    private:
        string name;
        string password;
        int numberOfCinemas;
        int numberOfStaffs;
        Cinema *cinemas;
        Staff *staffs;

    public:
        CinemaSystem(string = "UnknownCinemaSystem",  string = "UnknownPass", int = 0, int = 0);
        CinemaSystem(const CinemaSystem &cs);
        ~CinemaSystem();
        void setName(string name);
        void setPass(string password);
        void setNumOfCinemas(int NOC);
        void setNumOfStaffs(int NOS);
        void setCinemaArray(int NOC);
        void setStaffArray(int NOS);
        void setCinema(int i, int NOR, int NOC, string name);
        void setStaff(int i, string code, string name, string contact, string email);
        int getNumOfCinemas();
        int getNumOfStaffs();
        Cinema getCinema(int i);
        string getPass();
        friend istream &operator >> (istream &in, CinemaSystem &cs);
        friend ostream &operator << (ostream &out, const CinemaSystem &cs);
};

#endif