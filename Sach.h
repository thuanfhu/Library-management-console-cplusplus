#ifndef SACH_H
#define SACH_H
#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

class Sach {
private:
    int namXuatBan, soTrang, soLuong;
    string maSach, tenSach, tacGia;
public:
    Sach(string tenSach, string tacGia, int namXuatBan, int soTrang, int soLuong);
    Sach();
    void nhapInfo_Sach();
    string getMaSach();
    int getNamXuatBan();
    int getSoTrang();
    string getTenSach();
    string getTacGia();
    int getSoLuong();
    void setSoLuong(int &SL);
    string taoMaSach();
};

#endif
