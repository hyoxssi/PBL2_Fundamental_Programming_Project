#include "CinemaSystem.h"

CinemaSystem::CinemaSystem(string name, string password, int numberOfCinemas, int numberOfStaffs): name(name), password(password), numberOfCinemas(numberOfCinemas), numberOfStaffs(numberOfStaffs), cinemas(new Cinema [numberOfCinemas]), staffs(new Staff [numberOfStaffs]) {}

CinemaSystem::CinemaSystem(const CinemaSystem &cs): name(cs.name), password(cs.password), numberOfCinemas(cs.numberOfCinemas), numberOfStaffs(cs.numberOfCinemas), cinemas(new Cinema [numberOfCinemas]), staffs(new Staff [numberOfStaffs]) {
    for (int i = 0; i < numberOfCinemas; ++i) {
        this->cinemas[i] = cs.cinemas[i];
    }
    for (int i = 0; i < numberOfStaffs; ++i) {
        this->staffs[i] = cs.staffs[i];
    }
}

CinemaSystem::~CinemaSystem() {
    delete [] this->cinemas;
    delete [] this->staffs;
}

void CinemaSystem::setName(string name) {
    this->name = name;
}

void CinemaSystem::setPass(string password) {
    this->password = password;
}

void CinemaSystem::setNumOfCinemas(int NOC) {
    this->numberOfCinemas = NOC;
}

void CinemaSystem::setNumOfStaffs(int NOS) {
    this->numberOfStaffs = NOS;
}

void CinemaSystem::setCinemaArray(int NOC) {
    delete [] this->cinemas;
    this->cinemas = new Cinema [NOC];
}

void CinemaSystem::setStaffArray(int NOS) {
    delete [] this->staffs;
    this->staffs = new Staff [NOS];
}

void CinemaSystem::setCinema(int i, int NOR, int NOC, string name) {
    this->cinemas[i].setThis(NOR, NOC, name);
}

void CinemaSystem::setStaff(int i, string code, string name, string contact, string email) {
    this->staffs[i].setCode(code);
    this->staffs[i].setName(name);
    this->staffs[i].setPhone(contact);
    this->staffs[i].setEmail(email);
}

int CinemaSystem::getNumOfCinemas() {
    return this->numberOfCinemas;
}

int CinemaSystem::getNumOfStaffs() {
    return this->numberOfStaffs;
}

string CinemaSystem::getPass() {
    return this->password;
}

Cinema CinemaSystem::getCinema(int i) {
    return this->cinemas[i];
}

istream &operator >> (istream &in, CinemaSystem &cs) {
    //...
    return in;
}

ostream &operator << (ostream &out, const CinemaSystem &cs) {
    out << endl << endl;
    out << cs.name << endl << "Pass: " << cs.password << endl << "Số lượng rạp: " << cs.numberOfCinemas << endl;
    for (int i = 0; i < cs.numberOfCinemas; ++i) {
        out << cs.cinemas[i];
    }
    out << endl << endl;
    out << "Số lượng nhân viên: " << cs.numberOfStaffs << endl;
    out << "Danh sách nhân viên: " << endl;
    for (int i = 0; i < cs.numberOfStaffs; ++i) {
        out << i + 1 << ". " << cs.staffs[i];
    }
    return out;
}