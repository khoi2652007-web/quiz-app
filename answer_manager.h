#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Lớp cơ sở (Base class)
class BaseAnswerManager {
public:
    virtual ~BaseAnswerManager() {}

    // Các hàm ảo (virtual) sẽ được lớp con ghi đè
    virtual void recordAnswer(int questionIndex, char answer) = 0;
    virtual char getAnswer(int questionIndex) const = 0; // ĐÃ BỔ SUNG HÀM NÀY
    virtual bool showWarningIfSkipped(int totalQuestions) const = 0;
};

// Lớp AnswerManager kế thừa từ BaseAnswerManager
class AnswerManager : public BaseAnswerManager {
private:
    map<int, char> studentAnswers;

public:
    void recordAnswer(int questionIndex, char answer) override;
    char getAnswer(int questionIndex) const override; // ĐÃ BỔ SUNG HÀM NÀY
    vector<int> getSkippedQuestions(int totalQuestions) const;
    bool showWarningIfSkipped(int totalQuestions) const override;
    map<int, char> getAllAnswers() const;
};