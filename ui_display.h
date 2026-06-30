#pragma once
#include <string>
using namespace std;

class Candidate {
private:
    string ten;
    string mssv;
    string lop;

public:
    Candidate(string t, string m, string l);

    string getTen() const;
    string getMSSV() const;
    string getLop() const;
};

class UIDisplay {
public:
    void hienThiThongTinThiSinh(const Candidate& c);
    void hienThiTongSoCauHoi(int tongSoCau);
    bool xacNhanNopBai();
};