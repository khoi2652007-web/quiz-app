#pragma once
#include "data_loader.h"
#include "answer_manager.h"
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class result_calculator
{
private:
	time_t startTime; //Thời điiểm bắt đầu làm bài
	int correctCount; //Số câu thí ssinh trả lời đung
	double score; //điểm /10

	string reportCandidateName; //Tên thi sinh khi khai báo
	int reportTotalQuestions; //Tổng số câu

	friend ostream& operator<<(ostream& os, const result_calculator& calc);
public:
	result_calculator();

	//1.Bộ đêm thời gian khi bắt đầu làm bài
	void startTimer();
	long getElapsedSeconds() const;

	//2. Viet ham tinh diem
	void calculateScore(const vector<Question>& questions, const AnswerManager& answerMgr);

	//3.Viet ham IN RA bang tong ket chi tiet sau khi thi xong:
	void showResult(const string& candidateName, const vector<Question>& questions, const AnswerManager& answerMgr);
	double getScore() const { return score; }
	int getCorrectCount() const { return correctCount; }

};

ostream& operator<<(ostream& os, const result_calculator& calc);
  