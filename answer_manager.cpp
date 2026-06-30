#include "answer_manager.h"

using namespace std;

void AnswerManager::recordAnswer(int questionIndex, char answer) {
    studentAnswers[questionIndex] = answer;
}

// ĐÃ BỔ SUNG NỘI DUNG HÀM getAnswer
char AnswerManager::getAnswer(int questionIndex) const {
    auto it = studentAnswers.find(questionIndex);
    if (it != studentAnswers.end()) {
        return it->second; // Trả về đáp án nếu tìm thấy
    }
    return ' '; // Trả về khoảng trắng nếu thí sinh chưa làm câu này
}

vector<int> AnswerManager::getSkippedQuestions(int totalQuestions) const {
    vector<int> skipped;
    for (int i = 1; i <= totalQuestions; ++i) {
        if (studentAnswers.find(i) == studentAnswers.end()) {
            skipped.push_back(i);
        }
    }
    return skipped;
}

bool AnswerManager::showWarningIfSkipped(int totalQuestions) const {
    vector<int> skipped = getSkippedQuestions(totalQuestions);

    if (skipped.empty()) {
        return false;
    }

    cout << "\n[CANH BAO] Ban chua tra loi cac cau hoi sau: ";
    for (size_t i = 0; i < skipped.size(); ++i) {
        cout << skipped[i];
        if (i < skipped.size() - 1) {
            cout << ", ";
        }
    }
    cout << "\nBan co chac chan muon nop bai khong? (Y/N): ";
    return true;
}

map<int, char> AnswerManager::getAllAnswers() const {
    return studentAnswers;
}