#include "Movie.h"

Movie::Movie(string name, float rating, string director, string cast, string genre, int runtime): name(name), rating(rating), director(director), cast(cast), genre(genre), runtime(runtime) {}

Movie::Movie(const Movie &m): name(m.name), rating(m.rating), director(m.director), cast(m.cast), genre(m.genre), runtime(m.runtime), reviews(m.reviews), onAir(m.onAir) {}

Movie::~Movie() {}

void Movie::setName(string name) {
    this->name = name;
}

void Movie::setRating(float rating) {
    this->rating = rating;
}

void Movie::setDirector(string director) {
    this->director = director;
}

void Movie::setCast(string cast) {
    this->cast = cast;
}

void Movie::setGenre(string genre) {
    this->genre = genre;
}

void Movie::setRuntime(int runtime) {
    this->runtime = runtime;
}

void Movie::setReviews(string review) {
    this->reviews.insert_at_tail(review);
}

void Movie::setShowtimes2(int index, string quantity, string time) {
    onAir.setAOT(index, quantity, time);
}

void Movie::dis() {
    onAir.dis();
}

ostream &operator << (ostream &out,/* const*/ Movie &m) {
    out << m.name << endl << "Rating: " << m.rating << endl << "Dao dien: " << m.director << endl << "Dien vien: " << m.cast << endl << "The loai: " << m.genre << endl << "Thoi luong: " << m.runtime << endl << "Nhan xet: " << endl;
    m.reviews.display();
    // m.onAir.dis();
    out << endl << "Lich chieu: " << endl;
    out << m.onAir;
    return out;
}

string Movie::getName() {
    return name;
}

// void Movie::displayShowtimes() {
//     int opt;
//     cout << s.nameOfTheMovie << endl;
//     for (int i = 0; i < s.NOD; ++i) {
//         cout << i + 1 << ". " << s.AOD[i] << "\t\t";
//     }
//     cout << endl << "Chon ngay ma ban muon dat ve: ";
//     cin >> opt;
//     s.AOD[opt - 1].displayTime();
//     // out << "Chon gio ma ban muon dat ve: ";
//     //...
// }