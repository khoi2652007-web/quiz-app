#include "ui_display.h"
#include <iostream>
using namespace std;

Candidate::Candidate(string t, string m, string l) {
    ten = t;
    mssv = m;
    lop = l;
}

string Candidate::getTen() const {
    return ten;
}

string Candidate::getMSSV() const {
    return mssv;
}

string Candidate::getLop() const {
    return lop;
}

void UIDisplay::hienThiThongTinThiSinh(const Candidate& c) {
    cout << "Ten: " << c.getTen() << endl;
    cout << "MSSV: " << c.getMSSV() << endl;
    cout << "Lop: " << c.getLop() << endl;
}

void UIDisplay::hienThiTongSoCauHoi(int tongSoCau) {
    cout << "Tong so cau hoi: " << tongSoCau << endl;
}

bool UIDisplay::xacNhanNopBai() {
    int luaChon;

    cout << "Ban co chac muon nop bai?" << endl;
    cout << "1. Co" << endl;
    cout << "2. Khong" << endl;

    cin >> luaChon;

    return luaChon == 1;
}