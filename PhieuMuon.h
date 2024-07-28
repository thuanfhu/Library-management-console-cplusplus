#ifndef PHIEUMUON_H
#define PHIEUMUON_H

#include <bits/stdc++.h>
#include <Windows.h>
#include "ThuVien.h"
#include "DocGia.h"
#include "Sach.h"

using namespace std;

class PhieuMuon{
private:
    string maPhieuMuon, maDG, maSach;
    string ngayMuon, ngayTra;
public:
    string tenSach, tenDocGia;
    PhieuMuon();
    PhieuMuon(string maDG, string maSach, string ngayMuon);
    string getMaDG();
    string getMaSach();
    string getNgayMuon();
    string getNgayTra();
    string getMaPhieuMuon();
    string getTenSach();
    string getTenDG();
    string tinhNgayTra(string ngayMuon);
    string taoMaPhieuMuon();
    void nhapInfo_PhieuMuon();
    // Handle Error
    bool checkErrorCreateBorrow(string status, string input);
};

#endif