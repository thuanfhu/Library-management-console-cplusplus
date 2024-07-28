#include "PhieuMuon.h"
#include "console.h"
#include <Windows.h>

PhieuMuon::PhieuMuon(){
    this->maDG = this->maSach = this->ngayMuon = this->ngayTra = this->maPhieuMuon = this->tenSach = "";
}

PhieuMuon::PhieuMuon(string maDG, string maSach, string ngayMuon){
    this->maPhieuMuon = taoMaPhieuMuon();
    this->maDG = maDG;
    this->maSach = maSach;
    this->ngayMuon = ngayMuon;
    this->ngayTra = tinhNgayTra(this->ngayMuon);
}

string PhieuMuon::getTenSach(){
    return this->tenSach;
}

string PhieuMuon::getTenDG(){
    return this->tenDocGia;
}

string PhieuMuon::getMaDG(){
    return this->maDG;
}

string PhieuMuon::getMaSach(){
    return this->maSach;
}

string PhieuMuon::getNgayMuon(){
    return this->ngayMuon;
}

string PhieuMuon::getNgayTra(){
    return this->ngayTra;
}

string PhieuMuon::getMaPhieuMuon(){
    return this->maPhieuMuon;
}

string PhieuMuon::taoMaPhieuMuon() {
    static int soThuTu = 1;
    int soLuongPhieuMuon = soThuTu++;

    stringstream stream;
    stream << "PM" << setfill('0') << setw(3) << soLuongPhieuMuon;
    return stream.str();
}

// Tinh ngay tra
bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayToiDaTrongThang(int thang, int nam) {
    switch (thang) {
        case 2: return laNamNhuan(nam) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

string PhieuMuon::tinhNgayTra(string ngayMuon) {
    int ngay, thang, nam;
    char delim;

    stringstream ss(ngayMuon);
    ss >> ngay >> delim >> thang >> delim >> nam;

    thang += 3;
    if (thang > 12) {
        thang -= 12;
        nam += 1;
    }

    int ngayToiDa = soNgayToiDaTrongThang(thang, nam);
    if (ngay > ngayToiDa) {
        ngay = ngayToiDa;
    }

    stringstream ssNgayTra;
    ssNgayTra << (ngay < 10 ? "0" : "") << ngay << '/' << (thang < 10 ? "0" : "") << thang << '/' << nam;
    return ssNgayTra.str();
}

// Ham xoa dong o phieu muon 
void clearCreateBorrow(int line){
    for(int i = 93; i < 119; i++){
        gotoxy(i, line);
        cout << char(32);
        Sleep(1);
    }
}

bool PhieuMuon::checkErrorCreateBorrow(string status, string input){
    QuanLyThuVien library;
    vector<DocGia> listDocGia = library.getListDocGia();
    vector<Sach> listSach = library.getListSach();

    if(status == "MA DG"){
        for (auto it = listDocGia.begin(); it != listDocGia.end(); it++) {
            if(it->getMaDG() == input) return true;
        }
    }
    else if(status == "NGAY MUON"){
        stringstream ss(input);
        int day, month, year;
        char delimiter1, delimiter2;

        if (!(ss >> day >> delimiter1 >> month >> delimiter2 >> year)) return false;

        // Kiểm tra dấu phân cách
        if (delimiter1 != '/' || delimiter2 != '/') return false;

        // Kiểm tra tháng và năm
        if (month < 1 || month > 12 || year < 1) return false;

        // Kiểm tra số ngày trong tháng
        switch (month) {
            case 2: // Tháng 2 (xem xét năm nhuận)
                if (laNamNhuan(year)) {
                    if (day > 29) return false;
                } else {
                    if (day > 28) return false;
                }
                break;
            case 4: case 6: case 9: case 11:
                if (day > 30) return false;
                break;
            default:
                if (day > 31) return false;
        }
        return true;
    }
    else if(status == "MA SACH"){
        for (auto it = listSach.begin(); it != listSach.end(); it++) {
            if(it->getMaSach() == input) return true;
        }
    }

    return false;
}

// Ham nhap phieu muon
void PhieuMuon::nhapInfo_PhieuMuon(){
    cin.ignore(); 
    while(true){
        gotoxy(93, 3); getline(cin, this->maDG); 
        bool check1 = checkErrorCreateBorrow("MA DG", this->maDG);
        if(!check1){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            clearCreateBorrow(3); gotoxy(93, 3); cout << "Invalid Member ID"; Sleep(3000); clearCreateBorrow(3);
            gotoxy(93, 3); cout << "Please try again!"; Sleep(3000); clearCreateBorrow(3); TextColor(7);        
            continue;
        } 
        else break;
    }

    while(true){
        gotoxy(93, 5); getline(cin, this->ngayMuon); 
        bool check2 = checkErrorCreateBorrow("NGAY MUON", this->ngayMuon);
        if(!check2){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            clearCreateBorrow(5); gotoxy(93, 5); cout << "Invalid Input Format"; Sleep(3000); clearCreateBorrow(5);
            gotoxy(93, 5); cout << "Please try again!"; Sleep(3000); clearCreateBorrow(5); TextColor(7);        
            continue;
        } 
        else break;
    }

    this->ngayTra = tinhNgayTra(this->ngayMuon);
    gotoxy(93, 7); cout << this->ngayTra;

    while(true){
        gotoxy(93, 9); getline(cin, this->maSach);
        bool check3 = checkErrorCreateBorrow("MA SACH", this->maSach);
        if(!check3){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            clearCreateBorrow(9); gotoxy(93, 9); cout << "Invalid Book ID"; Sleep(3000); clearCreateBorrow(9);
            gotoxy(93, 9); cout << "Please try again!"; Sleep(3000); clearCreateBorrow(9); TextColor(7);      
            continue;
        } 
        else break;
    } 
    
    this->maPhieuMuon = taoMaPhieuMuon();

}


