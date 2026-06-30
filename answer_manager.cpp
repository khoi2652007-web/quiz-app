#include "answer_manager.h"

AnswerManager::AnswerManager() {}

void AnswerManager::recordAnswer(int questionNumber, char answer) {
    studentAnswers[questionNumber] = answer;
}

char AnswerManager::getAnswer(int questionNumber) const {
    auto it = studentAnswers.find(questionNumber);
    if (it != studentAnswers.end()) {
        return it->second;
    }
    return ' ';
}

std::vector<int> AnswerManager::getSkippedQuestions(int totalQuestions) const {
    std::vector<int> skipped;
    for (int i = 1; i <= totalQuestions; ++i) {
        if (studentAnswers.find(i) == studentAnswers.end()) {
            skipped.push_back(i);
        }
    }
    return skipped;
}

bool AnswerManager::showWarningIfSkipped(int totalQuestions) const {
    std::vector<int> skipped = getSkippedQuestions(totalQuestions);

    if (skipped.empty()) {
        return false;
    }

    std::cout << "\n[CANH BAO] Ban chua tra loi cac cau hoi sau: ";
    for (size_t i = 0; i < skipped.size(); ++i) {
        std::cout << skipped[i];
        if (i < skipped.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\nBan co chac chan muon nop bai khong? (Y/N): ";
    return true;
}

std::map<int, char> AnswerManager::getAllAnswers() const {
    return studentAnswers;
}