#include "Cinema.h"

Cinema::Cinema(int numberOfRows, int numberOfColumns, string name): numberOfRows(numberOfRows), numberOfColumns(numberOfColumns), numberOfSeats(numberOfRows * numberOfColumns), name(name), matrix(new Seat *[numberOfRows]) {
    int centerRow = numberOfRows / 2;
    int centerColumn = numberOfColumns / 2;
    for (int i = 0; i < this->numberOfRows; ++i) {
        this->matrix[i] = new Seat [this->numberOfColumns];
    }
    for (int i = 0; i < this->numberOfRows; ++i) {
        for (int j = 0; j < this->numberOfColumns; ++j) {
            this->matrix[i][j].setColumn(j + 1);
            this->matrix[i][j].setRow(i + 65);
        }
    }
    for (int i = 0; i < this->numberOfRows; ++i) {
        for (int j = 0; j < this->numberOfColumns; ++j) {
            // set price
            if (i == numberOfRows - 1) {
                this->matrix[i][j].setPrice(60000);
            }
            else if ((i >= centerRow - 2) && (i <= centerRow + 2) && (j >= centerColumn - 4) && (j <= centerColumn + 4)) {
                this->matrix[i][j].setPrice(50000);
            }
            else {
                this->matrix[i][j].setPrice(45000);
            }
        }
    }
}

Cinema::Cinema(const Cinema &c): numberOfSeats(c.numberOfSeats), numberOfRows(c.numberOfRows), numberOfColumns(c.numberOfColumns), name(c.name), matrix(new Seat *[numberOfRows]) {
    for (int i = 0; i < this->numberOfRows; ++i) {
        this->matrix[i] = new Seat [this->numberOfColumns];
    }
    for (int i = 0; i < this->numberOfRows; ++i) {
        for (int j = 0; j < this->numberOfColumns; ++j) {
            this->matrix[i][j] = c.matrix[i][j];
        }
    }
}

Cinema::~Cinema() {
    for (int i = 0; i < this->numberOfRows; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void Cinema::setThis(int NOR, int NOC, string name) {
    if (this->numberOfRows == 0) this->~Cinema();
    int centerRow = NOR / 2;
    int centerColumn = NOC / 2;
    this->name = name;
    this->numberOfRows = NOR;
    this->numberOfColumns = NOC;
    this->numberOfSeats = NOR * NOC;
    this->matrix = new Seat *[numberOfRows];
    for (int i = 0; i < this->numberOfRows; ++i) {
        this->matrix[i] = new Seat [this->numberOfColumns];
    }
    for (int i = 0; i < this->numberOfRows; ++i) {
        for (int j = 0; j < this->numberOfColumns; ++j) {
            this->matrix[i][j].setColumn(j + 1);
            this->matrix[i][j].setRow(i + 65);
        }
    }
    for (int i = 0; i < this->numberOfRows; ++i) {
        for (int j = 0; j < this->numberOfColumns; ++j) {
            // set price
            if (i == numberOfRows - 1) {
                this->matrix[i][j].setPrice(60000);
            }
            else if ((i >= centerRow - 2) && (i <= centerRow + 2) && (j >= centerColumn - 4) && (j <= centerColumn + 4)) {
                this->matrix[i][j].setPrice(50000);
            }
            else {
                this->matrix[i][j].setPrice(45000);
            }
        }
    }
}

void Cinema::paid(char row, int column, string file) {
    row = toupper(row);
    this->matrix[row - 65][column - 1].setStatus(1);
    //...
    // streampos n, m;
    // ifstream infile;
    // int soHang, soCot;
    // infile.open("rap1.txt");
    // infile >> soHang;
    // infile >> soCot;
    // int **temp;
    // temp = new int *[soHang];
    // for (int i = 0; i < soHang; ++i) {
    //     temp[i] = new int [soCot];
    // }
    // for (int i = 0; i < soHang; ++i) {
    //     for (int j = 0; j < soCot; ++j) {
    //         infile >> temp[i][j];
    //     }
    // }
    // infile.close();
    ofstream outfile;
    //temp[0][15] = 1;
    outfile.open(file, ios::out);
    outfile << numberOfRows << " " << numberOfColumns << endl;
    for (int i = 0; i < numberOfRows; ++i) {
        for (int j = 0; j < numberOfColumns; ++j) {
            outfile << matrix[i][j].getStatus() << " ";
        }
        if (i == numberOfRows - 1) break;
        outfile << endl;
    }
    outfile.close();
}

long Cinema::getPrice(char row, int column) {
    row = toupper(row);
    return matrix[row - 65][column - 1].getPrice();
}

long Cinema::income() {
    long i = 0;
    for (int i = 0; i < numberOfRows; ++i) {
        for (int j = 0; j < numberOfColumns; ++j) {
            if (matrix[i][j].getStatus() == 1) i = i + matrix[i][j].getPrice();
        }
    }
    return i;
}

bool checkFileWithFstream(string path) {
    ifstream isf(path);
    return isf.good();
}

void Cinema::read(string file) {
    ifstream infile;
    int x;
    infile.open(file);
    infile >> x;
    infile >> x;
    for (int i = 0; i < this->numberOfRows; ++i) {
        for (int j = 0; j < this->numberOfColumns; ++j) {
            infile >> x; 
            this->matrix[i][j].setStatus(x);
        }
    }
}

istream &operator >> (istream &in, Cinema &c) {
    ifstream infile;
    bool status;
    // cout << "Nhập tên hệ thống rạp: "; getline(in, c.nameOfCinemaSystem);
    string str1, str2 = ".txt";
    cout << "Nhập tên rạp: ";
    in >> str1;
    c.name = str1;
    fflush(stdin);
    str1 = str1 + str2;
    while (checkFileWithFstream(str1) == 0) {
        cout <<"Không tồn tại rạp, xin vui lòng nhập lại tên rạp: ";
        in >> str1;
        c.name = str1;
        fflush(stdin);
        char str2[50] = ".txt";
        str1 = str1 + str2;
    }
    infile.open(str1);
    for (int i = 0; i < c.numberOfRows; ++i) {
        delete [] c.matrix[i];
    }
    delete [] c.matrix;
    infile >> c.numberOfRows;
    infile >> c.numberOfColumns;
    int centerRow = c.numberOfRows / 2, centerColumn = c.numberOfColumns / 2;
    c.numberOfSeats = c.numberOfRows * c.numberOfColumns;
    c.matrix = new Seat *[c.numberOfRows];
    for (int i = 0; i < c.numberOfRows; ++i) {
        c.matrix[i] = new Seat [c.numberOfColumns];
    }
    for (int i = 0; i < c.numberOfRows; ++i) {
        for (int j = 0; j < c.numberOfColumns; ++j) {
            c.matrix[i][j].setColumn(j + 1);
            c.matrix[i][j].setRow(i + 65);
            infile >> status;
            c.matrix[i][j].setStatus(status);
            // set price
            if (i == c.numberOfRows - 1) {
                c.matrix[i][j].setPrice(60000);
            }
            else if ((i >= centerRow - 2) && (i <= centerRow + 2) && (j >= centerColumn - 4) && (j <= centerColumn + 4)) {
                c.matrix[i][j].setPrice(50000);
            }
            else {
                c.matrix[i][j].setPrice(45000);
            }
        }
    }
    infile.close();
    cout << "Hoàn thành nhập thông tin rạp phim!" << endl;
    return in;
}

void SET_COLOR(int color) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

ostream &operator << (ostream &out, const Cinema &c) {
    int distance = (c.numberOfColumns * 7 - 2) / 2;
    out << "Thong tin cua rap: Rap " << c.name << /*" thuộc hệ thống rạp " << c.nameOfCinemaSystem <<*/ " chua " << c.numberOfSeats << " cho ngoi, voi " << c.numberOfRows << " hang ghe va " << c.numberOfColumns << " cot ghe co so do nhu sau: " << endl << endl;
    SET_COLOR(14);
    for (int i = 0; i < distance; ++i) {
        out << "-";
    }
    out << "SCREEN";
    for (int i = 0; i < distance; ++i) {
        out << "-";
    }
    out << endl << endl;
    for (int i = 0; i < c.numberOfRows; ++i) {
        for (int j = 0; j < c.numberOfColumns; ++j) {
            if (j <= 8) {
                if (c.matrix[i][j].getStatus() == 1) SET_COLOR(4);
                else SET_COLOR(2);
                out << setw(5) << c.matrix[i][j].getRow() << "0" << c.matrix[i][j].getColumn();
            }
            else {
                if (c.matrix[i][j].getStatus() == 1) SET_COLOR(4);
                else SET_COLOR(2);
                out << setw(5) << c.matrix[i][j].getRow() << c.matrix[i][j].getColumn();
            }
        }
        out << endl;
    }
    out << endl;
    SET_COLOR(4);
    out << "Ghe da duoc dat truoc: mau do." << endl;
    SET_COLOR(2);
    out << "Ghe con trong: mau xanh." << endl;
    SET_COLOR(7);
    return out;
}