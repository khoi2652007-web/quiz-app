#pragma once
#include "data_loader.h"
#include <string>
#include <vector>
using namespace std;

class Candidate {
private:
    string ten;
    string mssv;
    string lop;

public:
    Candidate();
    Candidate(string t, string m, string l);
	void InputCandidateInfo();

    string getTen() const;
    string getMSSV() const;
    string getLop() const;
};

class UIDisplay {
public:
    void hienThiThongTinThiSinh(const Candidate& c) const;
    void hienThiTongSoCauHoi(int tongsocau) const;
    void hienThiCauHoi(const Question& q) const;
    bool xacNhanNopBai() const;
    char nhanPhimInput() const;
};
  