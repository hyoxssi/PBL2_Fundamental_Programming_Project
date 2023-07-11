#include "Menu.cpp"

#ifndef aRequest_h
#define aRequest_h

class aRequest {
    private:
        Date today;
        Cinema c1, c2, c3;
        CinemaSystem csCGV, csLOTTE, csMETIZ;
        int numberOfCustomers;
        int numberOfMovies;
        LinkedList<Customer> customers;
        Movie *movies;
        Menu menu;
    public:
        aRequest();
        void initialize();
        void start();
};

#endif