#ifndef THUVIEN_H
#define THUVIEN_H

#include "DocGia.h"
#include "Sach.h"
#include "PhieuMuon.h"
#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

class QuanLyThuVien {
private:
    static vector<DocGia> listDocGia;
    static vector<Sach> listSach;
    static vector<PhieuMuon> listPhieuMuon;
public:
    vector<PhieuMuon> getListPhieuMuon();
    vector<DocGia> getListDocGia();
    vector<Sach> getListSach();
    void themDocGia(DocGia dg);
    void xoaDocGia(string maDG);
    void hienThiFullDocGia();
    void themSach(Sach sach);
    void xoaSach(string maSach);
    void hienThiFullSach();
    string traCuuTenSach(string maSach);
    string traCuuTenDG(string maDG);
    string maPMto(string maPM, string ma);
    void tangGiamTSMuonDG(string maDG, string status);
    void tangGiamSLSachThuVien(string maSach, string status);
    void taoPhieuMuon(PhieuMuon pm);
    void xoaPhieuMuon(string maPM);
    void hienThiFullPhieuMuon();
    void hienThiInfoDGByID(string maDG);
    // Handle error
    bool checkErrorReturnBook(string status, string input);
    bool checkErrorSearchInfoDG(string status, string input);
};

vector<DocGia> QuanLyThuVien::listDocGia;
vector<Sach> QuanLyThuVien::listSach;
vector<PhieuMuon> QuanLyThuVien::listPhieuMuon;

#endif
