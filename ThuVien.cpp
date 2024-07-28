#include "ThuVien.h"
#include "console.h"

vector<PhieuMuon> QuanLyThuVien::getListPhieuMuon(){
    return this->listPhieuMuon;
}

vector<DocGia> QuanLyThuVien::getListDocGia(){
    return this->listDocGia;
}

vector<Sach> QuanLyThuVien::getListSach(){
    return this->listSach;
}


void QuanLyThuVien::themDocGia(DocGia dg){
    listDocGia.push_back(dg);
}

void QuanLyThuVien::xoaDocGia(string maDG){
    for (auto it = listDocGia.begin(); it != listDocGia.end(); it++) {
        if (it->getMaDG() == maDG) {
            listDocGia.erase(it);
            return;
        }
    }
}

void QuanLyThuVien::hienThiFullDocGia(){
    TextColor(7);
    int row = 5;
    for (auto it = listDocGia.begin(); it != listDocGia.end(); it++) {
        gotoxy(2, row); cout << it->getMaDG();
        gotoxy(10, row); cout << it->getHoDG(); 
        gotoxy(29, row); cout << it->getTenDG(); 
        gotoxy(37, row); cout << it->getSoDienThoai(); 
        gotoxy(56, row); cout << it->getGioiTinh(); 
        gotoxy(68, row); cout << it->getTongSachMuon(); 
        gotoxy(76, row); cout << (it->getTinhTrangThe() ? "ON" : "OFF");
        ++row;  
    }
}

void QuanLyThuVien::themSach(Sach sach){
    listSach.push_back(sach);
}

void QuanLyThuVien::hienThiFullSach(){
    TextColor(7);
    int row = 5;
    for (auto it = listSach.begin(); it != listSach.end(); it++) {
        gotoxy(2, row); cout << it->getMaSach();
        gotoxy(10, row); cout << it->getTenSach(); 
        gotoxy(40, row); cout << it->getNamXuatBan(); 
        gotoxy(46, row); cout << it->getTacGia(); 
        gotoxy(64, row); cout << it->getSoTrang(); 
        gotoxy(75, row); cout << it->getSoLuong();
        ++row;  
    }
}

void QuanLyThuVien::xoaSach(string maSach){
    for (auto it = listSach.begin(); it != listSach.end(); it++) {
        if (it->getMaSach() == maSach) {    
            listSach.erase(it);
            return;
        }
    }
}

string QuanLyThuVien::traCuuTenSach(string maSach) {
    for (auto it = listSach.begin(); it != listSach.end(); it++) {
        if (it->getMaSach() == maSach) {    
            return it->getTenSach();
        }
    }
    return "";
}

string QuanLyThuVien::traCuuTenDG(string maDG) {
    for (auto it = listDocGia.begin(); it != listDocGia.end(); it++) {
        if (it->getMaDG() == maDG) {    
            return it->getHoDG() + " " + it->getTenDG();
        }
    }
    return "";
}

void QuanLyThuVien::taoPhieuMuon(PhieuMuon pm){
    listPhieuMuon.push_back(pm);
}

void QuanLyThuVien::xoaPhieuMuon(string maPM){
    for (auto it = listPhieuMuon.begin(); it != listPhieuMuon.end(); it++) {
        if (it->getMaPhieuMuon() == maPM) {
            listPhieuMuon.erase(it);
            return;
        }
    }
}

void QuanLyThuVien::hienThiFullPhieuMuon(){
    TextColor(11);
    int row = 13;
    for (auto it = listPhieuMuon.begin(); it != listPhieuMuon.end(); it++) {
        gotoxy(13, row); cout << it->getMaPhieuMuon();
        gotoxy(20, row); cout << it->getTenSach(); 
        gotoxy(52, row); cout << it->getMaDG();
        gotoxy(59, row); cout << it->getTenDG();
        gotoxy(87, row); cout << it->getNgayMuon(); 
        gotoxy(98, row); cout << it->getNgayTra();
        ++row;  
    }
}

string QuanLyThuVien::maPMto(string maPM, string ma){
    for (auto it = listPhieuMuon.begin(); it != listPhieuMuon.end(); it++) {
        if (it->getMaPhieuMuon() == maPM) {
            if(ma == "MA SACH") return it->getMaSach();
            else if(ma == "MA DG") return it->getMaDG();
        }
    }
    return "";
}

// Tang, giam tong sach muon thong qua ma Doc Gia
void QuanLyThuVien::tangGiamTSMuonDG(string maDG, string status) {
    for (auto it = listDocGia.begin(); it != listDocGia.end(); it++) {
        if (it->getMaDG() == maDG) { 
            int TSMuon = it->getTongSachMuon();
            if (status == "GIAM" && TSMuon > 0) TSMuon--;
            else if (status == "TANG" && TSMuon < 3) TSMuon++;
            it->setTongSachMuon(TSMuon); break; 
        }
    }
}

void QuanLyThuVien::tangGiamSLSachThuVien(string maSach, string status) {
    for (auto it = listSach.begin(); it != listSach.end(); it++) {
        if (it->getMaSach() == maSach) { 
            int soLuongSach = it->getSoLuong();
            if (status == "GIAM") soLuongSach--;
            else if (status == "TANG") soLuongSach++;
            it->setSoLuong(soLuongSach); break; 
        }
    }
}

bool QuanLyThuVien::checkErrorReturnBook(string status, string input){
    if(status == "MA PM"){
        for (auto it = listPhieuMuon.begin(); it != listPhieuMuon.end(); it++) {
            if (it->getMaPhieuMuon() == input) return true;
        }
    }
    else if(status == "MA SACH"){
        for (auto it = listPhieuMuon.begin(); it != listPhieuMuon.end(); it++) {
            if (it->getMaSach() == input) return true;
        }
    }
    return false;
}

bool QuanLyThuVien::checkErrorSearchInfoDG(string status, string input){
    if(status == "MA DG"){
        for (auto it = listDocGia.begin(); it != listDocGia.end(); it++) {
            if (it->getMaDG() == input) return true;
        }
    }
    return false;
}

void QuanLyThuVien::hienThiInfoDGByID(string maDG){
    for (auto it = listDocGia.begin(); it != listDocGia.end(); it++) {
        if (it->getMaDG() == maDG) {
            gotoxy(5, 20); cout << it->getHoDG() + " " + it->getTenDG();
            gotoxy(33, 20); cout << it->getGioiTinh();
            gotoxy(38, 20); cout << it->getSoDienThoai();
        }
    }

    int soSachMuon = 0;
    for (auto it = listPhieuMuon.begin(); it != listPhieuMuon.end(); it++) {
        if(it->getMaDG() == maDG) ++soSachMuon;
    }
    int row = 19;
    for (auto it = listPhieuMuon.begin(); it != listPhieuMuon.end(); it++) {
        if(it->getMaDG() == maDG && soSachMuon == 1) {
            row = 20;
            gotoxy(52, row); cout << it->getMaSach();
            gotoxy(59, row); cout << it->getTenSach();
            gotoxy(91, row); cout << it->getNgayMuon();
            gotoxy(105, row); cout << it->getNgayTra();
            break;
        }
        else if(it->getMaDG() == maDG && soSachMuon == 0) break;
        else if(it->getMaDG() == maDG && soSachMuon > 1) {
            gotoxy(52, row); cout << it->getMaSach();
            gotoxy(59, row); cout << it->getTenSach();
            gotoxy(91, row); cout << it->getNgayMuon();
            gotoxy(105, row); cout << it->getNgayTra();
            ++row;
        }    
    }
}