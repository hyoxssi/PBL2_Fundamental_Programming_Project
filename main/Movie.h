#include "Showtimes.cpp"

#ifndef Movie_h
#define Movie_h

class Movie {
    private:
        string name;
        float rating;
        string director;
        string cast;
        string genre;
        int runtime; // unit: minute
        LinkedList<string> reviews;
        Showtimes onAir;
        
    public:
        Movie(string = "UnkownMovie", float = 5, string = "UnkownDirector", string = "UnkownCast", string = "UnkownGenre", int = 0);
        Movie(const Movie &m);
        ~Movie();
        void setName(string name);
        void setRating(float rating);
        void setDirector(string director);
        void setCast(string cast);
        void setGenre(string genre);
        void setRuntime(int runtime);
        void setReviews(string review);
        void setShowtimes2(int index, string quantity, string time);
        void dis();
        friend ostream &operator << (ostream &out,Movie &m);
        string getName();
};

#endif