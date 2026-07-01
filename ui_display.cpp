#include "ui_display.h"
#include <iostream>

using namespace std;

Candidate::Candidate() : ten(""), mssv(""), lop("") {}
Candidate::Candidate(string t, string m, string l) : ten(t), mssv(m), lop(l) {}

void Candidate::InputCandidateInfo() {
    cout << "\n========================================================" << endl;
    cout << "             NHAP THONG TIN THI SINH                    " << endl;
    cout << "========================================================" << endl;
    cout << "Ho va ten: ";
    getline(cin, ten);  

    cout << "MSSV: ";
    getline(cin, mssv);

    cout << "Lop: ";
    getline(cin, lop);
    cout << "--------------------------------------------------------" << endl;
}

string Candidate::getTen() const { return ten; }
string Candidate::getMSSV() const { return mssv; }
string Candidate::getLop() const { return lop; }

void UIDisplay::hienThiThongTinThiSinh(const Candidate& c) const {
    cout << "\n=== THONG TIN THI SINH ===" << endl;
    cout << "Ten: " << c.getTen() << endl;
    cout << "MSSV: " << c.getMSSV() << endl;
    cout << "Lop: " << c.getLop() << endl;
    cout << "==========================" << endl;
}

void UIDisplay::hienThiTongSoCauHoi(int tongsoCau) const {
    cout << "Tong so cau hoi trong he thong: " << tongsoCau << " cau." << endl;
}

void UIDisplay::hienThiThanhDieuHuong(int tongSoCau, int cauHienTai) const {
    cout << "\n--- THANH DIEU HUONG CAU HOI ---" << endl;
    cout << "Vi tri: ";
    for (int i = 1; i <= tongSoCau; ++i) {
        if (i == cauHienTai) {
            cout << "[*" << i << "] "; // Đánh dấu câu đang đứng bằng dấu *
        } else {
            cout << "[" << i << "] ";
        }
    }
    cout << "\n--------------------------------" << endl;
}

void UIDisplay::hienThiCauHoi(int sothutu, const Question& q) const {
    cout << "\nCau " << sothutu << ": " << q.getQuestionText() << endl;

    vector<string> danhsachdapan = q.getOptions();
    char dapan = 'a';
    for (size_t i = 0; i < danhsachdapan.size(); ++i) {
        cout << "  " << dapan << ") " << danhsachdapan[i] << endl;
        dapan++;
    }
}

bool UIDisplay::xacNhanNopBai() const {
    int luaChon;
    cout << "\n[POP-UP] Ban co chac chan muon nop bai khong?" << endl;
    cout << "1. Co, toi muon nop bai." << endl;
    cout << "2. Khong, toi muon kiem tra lai." << endl;
    cout << "Nhap lua chon (1 hoac 2): ";
    cin >> luaChon;
    cin.ignore(10000, '\n'); 
    return (luaChon == 1);
}


char UIDisplay::nhanPhimInput() const {
    char luaChon;
    cout << "\n[Huong dan]:" << endl;
    cout << " -> Nhap 'a', 'b', 'c', 'd' de CHON DAP AN" << endl;
    cout << " -> Nhap 'n' (Next) de SANG CAU TIEP THEO" << endl;
    cout << " -> Nhap 'p' (Previous) de QUAY LAI CAU TRUOC" << endl;
    cout << " -> Nhap 's' (Submit) de NOP BAI" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> luaChon;

    cin.ignore(10000, '\n'); 
    return tolower(luaChon); 
}