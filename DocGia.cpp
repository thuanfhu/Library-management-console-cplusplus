#include "DocGia.h"
#include "console.h"

string DocGia::taoMaDG() {
    static int soThuTu = 1;
    int soLuongDG = soThuTu++;

    stringstream stream;
    stream << "DG" << setfill('0') << setw(3) << soLuongDG;
    return stream.str();
}

DocGia::DocGia(string hoDG, string tenDG, string gioiTinh, string soDienThoai){
    this->maDG = taoMaDG();
    this->hoDG = hoDG;
    this->tenDG = tenDG;
    this->gioiTinh = gioiTinh;
    this->soDienThoai = soDienThoai;
    this->tongSachMuon = 0;
    this->tinhTrangThe = true;
}

DocGia::DocGia() {
    this->tongSachMuon = 0;
    this->hoDG = this->tenDG = this->soDienThoai = this->gioiTinh = this->maDG = "";
    this->tinhTrangThe = true;
}

// Handle error
void clearInputAddMemberByLine(int line){
    for(int i = 50; i <= 80; i++){
        gotoxy(i, line); cout << char(32); Sleep(1);
    }
}

bool isValidPhoneNumber(string phoneNumber) {
    if (phoneNumber.length() != 10) return false;
    for (char ch : phoneNumber) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

void DocGia::nhapInfo_DG() {  
    gotoxy(50, 15);
    getline(cin, this->hoDG); 

    gotoxy(50, 17); 
    getline(cin, this->tenDG);

    // Handle Error so dien thoai chi co 10 chu so toi da va khong co ki tu chu
    while(true){
        gotoxy(50, 19); getline(cin, this->soDienThoai);
        if (isValidPhoneNumber(this->soDienThoai)) break;
        else {
            clearInputAddMemberByLine(21);
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(50, 19); cout << "Invalid phone number input"; Sleep(2000); clearInputAddMemberByLine(19);
            gotoxy(50, 19); cout << "Please try again!"; Sleep(2000); clearInputAddMemberByLine(19);
            TextColor(14);
            continue;
        }
    }

    // Handle Error chi co gioi tinh nam hoac nu
    while(true){
        gotoxy(50, 21); getline(cin, this->gioiTinh); 
        string ketQua = this->gioiTinh;
        for (char& ch : ketQua) ch = tolower(ch);
        if(ketQua != "nam" && ketQua != "nu") {
            clearInputAddMemberByLine(21); 
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(50, 21); cout << "Invalid gender input"; Sleep(2000); clearInputAddMemberByLine(21);
            gotoxy(50, 21); cout << "Please try again!"; Sleep(2000); clearInputAddMemberByLine(21);
            TextColor(14);
            continue;
        }
        else break;
    }
    
    this->tinhTrangThe = true;
    this->maDG = taoMaDG();
}


string DocGia::getMaDG(){   
    return this->maDG;
}

string DocGia::getHoDG(){
    return this->hoDG;
}

string DocGia::getTenDG(){
    return this->tenDG;
}

string DocGia::getGioiTinh(){
    return this->gioiTinh;
}

string DocGia::getSoDienThoai(){
    return this->soDienThoai;
}

bool DocGia::getTinhTrangThe(){
    return this->tinhTrangThe;
}

int DocGia::getTongSachMuon(){
    return this->tongSachMuon;
}

void DocGia::setTongSachMuon(int &tsMuon){
    this->tongSachMuon = tsMuon;
}