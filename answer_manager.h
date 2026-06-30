#ifndef ANSWER_MANAGER_H
#define ANSWER_MANAGER_H

#include <map>
#include <vector>
#include <iostream>

class AnswerManager {
private:
    std::map<int, char> studentAnswers;

public:
    AnswerManager();

    void recordAnswer(int questionNumber, char answer);
    char getAnswer(int questionNumber) const;
    std::vector<int> getSkippedQuestions(int totalQuestions) const;
    bool showWarningIfSkipped(int totalQuestions) const;
    std::map<int, char> getAllAnswers() const;
};

#endif // ANSWER_MANAGER_H