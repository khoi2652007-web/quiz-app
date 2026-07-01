#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question {
private:
    int id;                           
    string question_text;        
    vector<string> options; 
    char correct_answer;              

public:
    Question() : id(0), correct_answer(' ') {}
    Question(int id, const string& text, const vector<string>& opts, char answer)
        : id(id), question_text(text), options(opts), correct_answer(answer) {}
    int getId() const { return id; }
    string getQuestionText() const { return question_text; }
    vector<string> getOptions() const { return options; }
    char getCorrectAnswer() const { return correct_answer; }
};

class DataLoader {
public:
    static vector<Question> loadData(const string& filename);
};