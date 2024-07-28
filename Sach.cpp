#include "Sach.h"
#include "console.h"

string Sach::taoMaSach() {
    static int soThuTu = 1;
    int soLuongSach = soThuTu++;

    stringstream stream;
    stream << "BK" << setfill('0') << setw(3) << soLuongSach;
    return stream.str();
}

Sach::Sach(string tenSach, string tacGia, int namXuatBan, int soTrang, int soLuong){
    this->maSach = taoMaSach();
    this->tenSach = tenSach;
    this->soTrang = soTrang;
    this->tacGia = tacGia;
    this->namXuatBan = namXuatBan;
    this->soLuong = soLuong;
}

Sach::Sach(){
    this->namXuatBan = this->soTrang = this->soLuong = 0;
    this->tenSach = this->tacGia = "";
}

void Sach::setSoLuong(int &SL){
    this->soLuong = SL;
}

void clearInputInfoBookByLine(int line){
    for(int i = 93; i < 119; i++){
        gotoxy(i, line); cout << char(32);
        Sleep(1);
    }
}

void Sach::nhapInfo_Sach(){
    gotoxy(93, 3); cin.ignore();
    getline(cin, tenSach);

    gotoxy(93, 5);
    getline(cin, tacGia);

    while(true){
        gotoxy(93, 7); cin >> namXuatBan;
        if(namXuatBan < 1){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
            clearInputInfoBookByLine(7); TextColor(4);
            gotoxy(93, 7); cout << "Invalid year publication"; Sleep(3000); clearInputInfoBookByLine(7);
            gotoxy(93, 7); cout << "Please try again!"; Sleep(3000); clearInputInfoBookByLine(7); TextColor(7);
            continue;
        }
        else break;
    }   

    while(true){
        gotoxy(93, 9); cin >> soTrang;
        if(soTrang < 1){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
            clearInputInfoBookByLine(9); TextColor(4);
            gotoxy(93, 9); cout << "Invalid book page number"; Sleep(3000); clearInputInfoBookByLine(9);
            gotoxy(93, 9); cout << "Please try again!"; Sleep(3000); clearInputInfoBookByLine(9); TextColor(7);
            continue;
        }
        else break;
    }

    while(true){
        gotoxy(93, 11); cin >> soLuong;
        if(soLuong < 1){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); 
            clearInputInfoBookByLine(11); TextColor(4);
            gotoxy(93, 11); cout << "Invalid number of books"; Sleep(3000); clearInputInfoBookByLine(11);
            gotoxy(93, 11); cout << "Please try again!"; Sleep(3000); clearInputInfoBookByLine(11); TextColor(7);
            continue;
        }
        else break;
    }

    maSach = taoMaSach();
}

int Sach::getSoLuong(){
    return this->soLuong;
}

string Sach::getMaSach() {
    return this->maSach;
}

int Sach::getNamXuatBan() {
    return this->namXuatBan;
}

int Sach::getSoTrang() {
    return this->soTrang;
}

string Sach::getTenSach() {
    return this->tenSach;
}

string Sach::getTacGia() {
    return this->tacGia;
}
