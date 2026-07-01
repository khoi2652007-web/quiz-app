#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Lớp cơ sở (Base class)
class BaseAnswerManager {
public:
    virtual ~BaseAnswerManager() {}

    virtual void recordAnswer(int questionIndex, char answer) = 0;
    virtual char getAnswer(int questionIndex) const = 0;
    virtual bool showWarningIfSkipped(int totalQuestions) const = 0; // Kiểu dữ liệu: bool
};

// Lớp AnswerManager kế thừa từ BaseAnswerManager
class AnswerManager : public BaseAnswerManager {
private:
    map<int, char> studentAnswers;

public:
    void recordAnswer(int questionIndex, char answer) override;
    char getAnswer(int questionIndex) const override;
    vector<int> getSkippedQuestions(int totalQuestions) const;
    bool showWarningIfSkipped(int totalQuestions) const override; // Đảm bảo đồng bộ kiểu bool ở đây
    map<int, char> getAllAnswers() const;
};