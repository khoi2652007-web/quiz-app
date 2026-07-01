#pragma once
#include <string>
#include <vector>
#include "data_loader.h" // Nhập lớp Question của Duy để truyền trực tiếp đối tượng

using namespace std;

// Class lưu trữ thông tin thí sinh
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

// Class quản lý giao diện hiển thị
class UIDisplay {
public:
    void hienThiThongTinThiSinh(const Candidate& c) const;
    void hienThiTongSoCauHoi(int tongsocau) const;
    void hienThiThanhDieuHuong(int tongSoCau, int cauHienTai) const;
    void hienThiCauHoi(int sothutu, const Question& q) const;
    bool xacNhanNopBai() const;
    char nhanPhimInput() const;
};