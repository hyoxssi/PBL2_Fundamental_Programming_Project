#include "aRequest.h"

aRequest::aRequest(): today(26,12,2022), c1(14, 16, "CinemaOfCGV1"), c2(10, 13, "CinemaOfLOTTE3"), c3(7, 10, "CinemaOfMETIZ4") {}

void aRequest::initialize() {
    float t1;
    int t2, t3;
    string t, a, b, c;
    ifstream infile;
    // initialization of customers
    infile.open("..\\database\\Customer.txt");
    getline(infile, t);
    this->numberOfCustomers = stoi(t);
    string line;
    while (getline(infile, line)) {
        Customer temp;
        stringstream linestream(line);
        string value;
        int j = 1;
        while (getline(linestream, value, ',')) {
            switch (j) {
                case 1:
                    temp.setName(value); break;
                case 2:
                    temp.setPhone(value); break;
                case 3:
                    temp.setEmail(value); break;
                case 4:
                    temp.setPass(value); break;
            }
            ++j;
        }
        this->customers.insert_at_tail(temp);
    }
    infile.close();
    // customers.display();
    // initialization of movies
    infile.open("..\\database\\Movie.txt");
    // Showtimes x;
    getline(infile, t);
    this->numberOfMovies = stoi(t);
    movies = new Movie [numberOfMovies];
    for (int i = 0; i < numberOfMovies; ++i) {
        // Movie temp1("?", 0, "?", "?", "?", 0);
        getline(infile, t);
        movies[i].setName(t);
        getline(infile, t);
        t1 = stof(t);
        movies[i].setRating(t1);
        getline(infile, t);
        movies[i].setDirector(t);
        getline(infile, t);
        movies[i].setCast(t);
        getline(infile, t);
        movies[i].setGenre(t);
        getline(infile, t);
        t2 = stoi(t);
        movies[i].setRuntime(t2);
        getline(infile, t);
        movies[i].setReviews(t);
        getline(infile, t);
        movies[i].setReviews(t);
        getline(infile, t);
        movies[i].setReviews(t);
        //initialization of Showtimes
        // movies[i].setShowtimes1();
        for (int j = 0; j < 6; ++j) {
            getline(infile, t);
            getline(infile, t);
            getline(infile, a);
            movies[i].setShowtimes2(j, t, a);
        }
        // movies[i].dis();
        // this->movies.insert_at_tail(movies[i]);
    }
    infile.close();
    // movies.display();
    // for (int i = 0; i < numberOfMovies; ++i) {
    //     cout << i + 1 << ". " << movies[i] << endl;
    // }
    // initialization of CGV Cinema System
    infile.open("..\\database\\CGV.txt");
    getline(infile, t);
    csCGV.setName(t);
    getline(infile, t);
    csCGV.setPass(t);
    getline(infile, t);
    t2 = stoi(t);
    csCGV.setNumOfCinemas(t2);
    getline(infile, t);
    t2 = stoi(t);
    csCGV.setNumOfStaffs(t2);
    csCGV.setCinemaArray(csCGV.getNumOfCinemas());
    csCGV.setStaffArray(csCGV.getNumOfStaffs());
    for (int i = 0; i < csCGV.getNumOfCinemas(); ++i) {
        t = "CinemaOfCGV" + to_string(i + 1);
        infile >> t2;
        infile >> t3;
        csCGV.setCinema(i, t2, t3, t);
    }
    getline(infile, t);
    for (int i = 0; i < csCGV.getNumOfStaffs(); ++i) {
        getline(infile, t);
        getline(infile, a);
        getline(infile, b);
        getline(infile, c);
        csCGV.setStaff(i, t, a, b, c);
    }
    infile.close();
    // cout << csCGV;
    // initialization of Lotte Cinema System
    infile.open("..\\database\\LOTTE.txt");
    getline(infile, t);
    csLOTTE.setName(t);
    getline(infile, t);
    csLOTTE.setPass(t);
    getline(infile, t);
    t2 = stoi(t);
    csLOTTE.setNumOfCinemas(t2);
    getline(infile, t);
    t2 = stoi(t);
    csLOTTE.setNumOfStaffs(t2);
    csLOTTE.setCinemaArray(csLOTTE.getNumOfCinemas());
    csLOTTE.setStaffArray(csLOTTE.getNumOfStaffs());
    for (int i = 0; i < csLOTTE.getNumOfCinemas(); ++i) {
        t = "CinemaOfLOTTE" + to_string(i + 1);
        infile >> t2;
        infile >> t3;
        csLOTTE.setCinema(i, t2, t3, t);
    }
    getline(infile, t);
    for (int i = 0; i < csLOTTE.getNumOfStaffs(); ++i) {
        getline(infile, t);
        getline(infile, a);
        getline(infile, b);
        getline(infile, c);
        csLOTTE.setStaff(i, t, a, b, c);
    }
    infile.close();
    // cout << csLOTTE;
    // initialization of Metiz Cinema System
    infile.open("..\\database\\METIZ.txt");
    getline(infile, t);
    csMETIZ.setName(t);
    getline(infile, t);
    csMETIZ.setPass(t);
    getline(infile, t);
    t2 = stoi(t);
    csMETIZ.setNumOfCinemas(t2);
    getline(infile, t);
    t2 = stoi(t);
    csMETIZ.setNumOfStaffs(t2);
    csMETIZ.setCinemaArray(csMETIZ.getNumOfCinemas());
    csMETIZ.setStaffArray(csMETIZ.getNumOfStaffs());
    for (int i = 0; i < csMETIZ.getNumOfCinemas(); ++i) {
        t = "CinemaOfMETIZ" + to_string(i + 1);
        infile >> t2;
        infile >> t3;
        csMETIZ.setCinema(i, t2, t3, t);
    }
    getline(infile, t);
    for (int i = 0; i < csMETIZ.getNumOfStaffs(); ++i) {
        getline(infile, t);
        getline(infile, a);
        getline(infile, b);
        getline(infile, c);
        csMETIZ.setStaff(i, t, a, b, c);
    }
    infile.close();
    // cout << csMETIZ;
    // initialization of Cinema
    c1.read("..\\database\\CinemaOfCGV1.txt");
    c2.read("..\\database\\CinemaOfLOTTE3.txt");
    c3.read("..\\database\\CinemaOfMETIZ4.txt");
}

void aRequest::start() {
    char r; int c;
    int opt, opt1, opt2, opt3, opt4, opt5;
    string phone, pass;
    menu.intro();
    while (true) {
        opt = menu.login();
        if (opt == 5) break;
        switch(opt) {
            case 1: {
                cout << "Nhap so dien thoai: ";
                cin >> phone;
                cout << "Nhap mat khau: ";
                cin >> pass;
                cout << endl << "Dang nhap thanh cong!" << endl;
                system("pause");
                break;
            }
            case 2: {
                cout << "Nhap mat khau: ";
                cin >> pass;
                while (pass != csCGV.getPass()) {
                    cout << "Mat khau sai, vui long nhap lai: ";
                    cin >> pass;
                }
                cout << endl << "Dang nhap thanh cong!" << endl;
                system("pause");
                break;
            }
            case 3: {
                cout << "Nhap mat khau: ";
                cin >> pass;
                while (pass != csLOTTE.getPass()) {
                    cout << "Mat khau sai, vui long nhap lai: ";
                    cin >> pass;
                }
                cout << endl << "Dang nhap thanh cong!" << endl;
                system("pause");
                break;
            }
            case 4: {
                cout << "Nhap mat khau: ";
                cin >> pass;
                while (pass != csMETIZ.getPass()) {
                    cout << "Mat khau sai, vui long nhap lai: ";
                    cin >> pass;
                }
                cout << endl << "Dang nhap thanh cong!" << endl;
                system("pause");
                break;
            }
            default: break;
        }
        while(true) {
            if (opt == 1) {
                system("cls");
                menu.CustomerInterface();
                cin >> opt1;
                if (opt1 == 5) break;
                switch (opt1) {
                    case 1: {
                        system("cls");
                        cout << "Danh sach phim " << endl;
                        for (int i = 0; i < numberOfMovies; ++i) {
                            cout << i + 1 << ". " << movies[i].getName() << endl;
                        }
                        cout << "16. Quay lai." << endl;
                        cout << "Chon phim ma ban muon dat ve: ";
                        cin >> opt2;
                        if (opt2 == 16) break;
                        else {
                            system("cls");
                            cout << "Chon cum rap ban muon dat ve (1. CGV, 2. LOTTE, 3.METIZ): ";
                            cin >> opt5;
                            cout << endl;
                            cout << movies[opt2];
                            cout << "Chon ngay ban muon dat ve: ";
                            cin >> opt3;
                            cout << "Chon khung gio ban muon dat ve: ";
                            cin >> opt4;
                            system("cls");
                            switch (opt5) {
                                case 1: {
                                    cout << c1;
                                    cout << "Nhap hang ghe ma ban muon dat: ";
                                    cin >> r;
                                    cout << "Nhap so ghe ma ban muon dat: ";
                                    cin >> c;
                                    c1.paid(r, c, "..\\database\\CinemaOfCGV1.txt");
                                    cout << endl << "Dat ve thanh cong!" << endl;
                                    cout << "So tien ma ban phai thanh toan la " << c1.getPrice(r, c) << " VND." << endl << endl;
                                    system("pause");
                                    break;
                                }
                                case 2: {
                                    cout << c2;
                                    cout << "Nhap hang ghe ma ban muon dat: ";
                                    cin >> r;
                                    cout << "Nhap so ghe ma ban muon dat: ";
                                    cin >> c;
                                    c2.paid(r, c, "..\\database\\CinemaOfLOTTE3.txt");
                                    cout << endl << "Dat ve thanh cong!" << endl << endl;
                                    system("pause");
                                    break;
                                }
                                case 3: {
                                    cout << c3;
                                    cout << "Nhap hang ghe ma ban muon dat: ";
                                    cin >> r;
                                    cout << "Nhap so ghe ma ban muon dat: ";
                                    cin >> c;
                                    c3.paid(r, c, "..\\database\\CinemaOfMETIZ4.txt");
                                    cout << endl << "Dat ve thanh cong!" << endl << endl;
                                    system("pause");
                                    break;
                                }
                                default: break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        break;
                    }
                    case 3: {
                        break;
                    }
                    case 4: {
                        break;
                    }
                    case 5: break;
                    default: break;
                }
            }
            else {
                switch (opt) {
                    case 2: {
                        cout << csCGV;
                        //cout << endl << "Doanh thu: " << c1.income();
                        break;
                    }
                    case 3: {
                        cout << csLOTTE;
                        //cout << endl << "Doanh thu: " << c2.income();
                        break;
                    }
                    case 4: {
                        cout << csMETIZ;
                        //cout << endl << "Doanh thu: " << c3.income();
                        break;
                    }
                    default: break;
                }
                cout << endl << endl << "Danh sach thong tin khach hang: " << endl;
                customers.display();
                cout << endl;
                system("pause");
                break;
            }
        }
    }
    cout << "Cam on ban da su dung ung dung!";
}