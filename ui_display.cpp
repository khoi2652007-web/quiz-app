#include "ui_display.h"
#include <iostream>
using namespace std;


Candidate::Candidate() : ten(""), mssv(""), lop("") {}
Candidate::Candidate(string t, string m, string l) : ten(t), mssv(m), lop(l) {}

void Candidate::InputCandidateInfo()
{
    cout << "\n Nhap thong tin thi sinh \n";
    cout << "Ho va ten: ";
    getline(cin, ten);

    cout << "MSSV: ";
    getline(cin, mssv);

    cout << "Lop: ";
    getline(cin, lop);
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

void UIDisplay::hienThiThongTinThiSinh(const Candidate& c) const {
    cout << "Ten: " << c.getTen() << endl;
    cout << "MSSV: " << c.getMSSV() << endl;
    cout << "Lop: " << c.getLop() << endl;
}

void UIDisplay::hienThiTongSoCauHoi(int tongsoCau) const {
    cout << "Tong so cau hoi: " << tongsoCau << endl;
}

bool UIDisplay::xacNhanNopBai() const {
    int luaChon;

    cout << "Ban co chac muon nop bai?" << endl;
    cout << "1. Co" << endl;
    cout << "2. Khong" << endl;
    cout << "Nhap lua chon (1 hoac 2): ";
    cin >> luaChon;
    cin.ignore();
    return luaChon == 1;
}


void UIDisplay::hienThiCauHoi(const Question& q) const {
    cout << "\nCau " << q.getId() << ": " << q.getQuestionText() << endl;
    vector<string> danhsachdapan = q.getOptions();
    char dapan = 'a';
    for (size_t i = 0; i < danhsachdapan.size(); ++i) {
        cout << "  " << dapan << ") " << danhsachdapan[i] << endl;
        dapan++;
    }
}
char UIDisplay::nhanPhimInput() const
{
    char luaChon;
    cout << "\nNhap dap an: ";
    cin >> luaChon;

    cin.ignore(10000, '\n');

    return luaChon;

}
