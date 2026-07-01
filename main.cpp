#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "data_loader.h"
#include "ui_display.h"
#include "answer_manager.h"
#include "result_calculator.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    // 1. Khởi tạo và nhập thông tin(Hân)
    Candidate student;
    student.InputCandidateInfo();

    // 2. Đọc dữ liệu câu hỏi từ file(Duy)
    vector<Question> examQuestions = DataLoader::loadData("input.txt");
    int totalQuestions = examQuestions.size();

    if (totalQuestions == 0) {
        cout << "[Thông báo] Không có dữ liệu câu hỏi hoặc không tìm thấy file. Chương trình kết thúc.\n";
        return 1;
    }

    // 3. Khởi tạo hiển thị(Hân) và quản lý câu trả lời(Huy)
    UIDisplay ui;
    AnswerManager am;
    
    // Khởi tạo bộ tính điểm của Tâm và BẮT ĐẦU BẤM GIỜ
    result_calculator calculator;
    calculator.startTimer(); 

    int currentIndex = 0; // Chỉ số câu hỏi hiện tại trong vector
    bool isFinished = false;

    cout << "\n=== BẮT ĐẦU PHIÊN LÀM BÀI ===\n";

    while (!isFinished) {
        system("cls"); 
        // Lấy câu hỏi từ danh sách của Duy
        const Question& currentQ = examQuestions[currentIndex];
        cout << "\n========================================================" << endl;
        ui.hienThiThongTinThiSinh(student);
        ui.hienThiTongSoCauHoi(totalQuestions);

        // nội dung câu hỏi và các lựa chọn(Hân)
        ui.hienThiCauHoi(currentQ);
        
        char savedAns = am.getAnswer(currentQ.getId());
        cout << "-> Đáp án bạn chọn: [" << savedAns << "]" << endl;
        cout << "(Lệnh điều hướng: 'p': Câu trước | 'n': Câu tiếp | 's': Nộp bài)" << endl;

        // Nhận ký tự điều hướng hoặc đáp án(Hân)
        char input = ui.nhanPhimInput();

        // Xử lý logic luồng chính(Khôi)
        if (input == 's' || input == 'S') {
            // Hiển thị Pop-up hỏi muốn nộp không(Hân)
            if (ui.xacNhanNopBai()) {
                isFinished = true;
            }
        } 
        else if (input == 'n' || input == 'N') {
            if (currentIndex < totalQuestions - 1) {
                currentIndex++;
            } else {
                cout << "\nĐây đã là câu hỏi cuối cùng!" << endl;
                Sleep(1000); // Giữ thông báo lại 1 giây trước khi xóa màn hình
            }
        } 
        else if (input == 'p' || input == 'P') {
            if (currentIndex > 0) {
                currentIndex--;
            } else {
                cout << "\nĐây đã là câu hỏi đầu tiên!" << endl;
                Sleep(1000); 
            }
        } 
        else {
            char epkieu = tolower(input);
            
            // Kiểm tra ký tự nhập vào  
            if (epkieu >= 'a' && epkieu < 'a' + currentQ.getOptions().size()) {
                am.recordAnswer(currentQ.getId(), epkieu);
                
                // Tự động chuyển sang câu tiếp theo sau khi chọn đáp án 
                if (currentIndex < totalQuestions - 1) {
                    currentIndex++;
                }
            } else {
                // điều hướng hoặc đáp án không hợp lệ
                cout << "\nPhím bấm hoặc đáp án không hợp lệ! Vui lòng chọn lại." << endl;
                Sleep(1000);
            }
        }
    }

    system("cls");

    // 4. logic Nộp bài
    if (isFinished) {
        // hàm tính điểm(Tâm)
        calculator.calculateScore(examQuestions, am);

        // hàm hiển thị bảng điểm + xem lại bài(Tâm)
        calculator.showResult(student.getTen(), examQuestions, am);

        // kết quả
        cout << "\n========================================================" << endl;
        cout << ">>> KẾT QUẢ: <<<" << endl;
        cout << calculator << endl; 
        cout << "========================================================" << endl;
    }

    return 0;
};