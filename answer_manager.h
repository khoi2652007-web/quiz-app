#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Lớp cơ sở để thể hiện tính kế thừa theo yêu cầu OOP của Khôi
class BaseAnswerManager {
public:
    virtual ~BaseAnswerManager() {}

    // Các hàm ảo sẽ được lớp con ghi đè
    virtual void recordAnswer(int questionIndex, char answer) = 0;
    virtual bool showWarningIfSkipped(int totalQuestions) const = 0;
};

// Lớp AnswerManager kế thừa từ BaseAnswerManager
class AnswerManager : public BaseAnswerManager {
private:
    map<int, char> studentAnswers;

public:
    void recordAnswer(int questionIndex, char answer) override;
    vector<int> getSkippedQuestions(int totalQuestions) const;
    bool showWarningIfSkipped(int totalQuestions) const override;
    map<int, char> getAllAnswers() const;
};