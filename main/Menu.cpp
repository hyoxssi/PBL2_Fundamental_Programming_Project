#include "Menu.h"

void Menu::intro() {
    system("cls");
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|            PBL2: DO AN CO SO LAP TRINH                |" << endl;
    cout << "|   UNG DUNG DAT VE XEM PHIM VA QUAN LY RAP CHIEU PHIM  |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|    Giang vien huong dan: GVC. ThS Tran Ho Thuy Tien   |" << endl;
    cout << "|         Sinh vien thuc hien: Tran Trong Hieu          |" << endl;
    cout << "|-------------------------------------------------------|" << endl << endl;
    system("pause");
}

int Menu::login() {
    int opt, opt1;
    string phone, pass;
    system("cls");
    cout << "Chao ngay moi!" << endl << endl;
    cout << "Ban muon dang nhap voi tu cach:" << endl << "1. Khach hang." << endl << "2. Quan ly rap chieu phim." << endl << "3. Thoat ung dung." << endl << endl;
    cout << "Nhap lua chon cua ban: "; 
    cin >> opt;
    while (opt < 1 || opt > 3) {
        cout << "Vui long nhap lai: ";
        cin >> opt;
    }
    cout << endl;
    if (opt == 1) return 1;
    else if (opt == 3) return 5;
    else {
        cout << "Ban muon dang nhap voi tu cach la quan ly cua: " << endl << "1. CGV Cinema" << endl << "2. LOTTE Cinema" << endl << "3. METIZ Cinema" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> opt1;
        if (opt1 == 1) return 2;
        else if (opt1 == 2) return 3;
        else if (opt1 == 3) return 4;
    }
    return 0;
}

void Menu::CSInterface() {

}

void Menu::CustomerInterface() {
    cout << "Chao Thien Anh," << endl << endl;
    cout << "1. Dat ve xem phim." << endl << "2. Doi so dien thoai." << endl << "3. Doi dia chi thu dien tu" << endl << "4. Doi mat khau." << endl << "5. Dang xuat." << endl << endl;
    cout << "Nhap lua chon cua ban: ";
}