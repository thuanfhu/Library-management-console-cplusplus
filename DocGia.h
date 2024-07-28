#ifndef DOCGIA_H
#define DOCGIA_H

#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

class DocGia {
private:
    int tongSachMuon;
    string maDG, hoDG, tenDG, gioiTinh, soDienThoai;
    bool tinhTrangThe;
public:
    DocGia(string hoDG, string tenDG, string gioiTinh, string soDienThoai);
    DocGia();
    void nhapInfo_DG();
    int getTongSachMuon();
    string getMaDG();
    string getHoDG();
    string getTenDG();
    string getGioiTinh();
    string getSoDienThoai();
    bool getTinhTrangThe();
    void setTongSachMuon(int &tsMuon);
    string taoMaDG();
};

#endif
