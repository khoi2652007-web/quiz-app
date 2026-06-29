 
// NHIEM VU CUA Minh Tâm  (theo de bai duoc giao):
//   1. Viet bo dem thoi gian (timer)
//   2. Viet ham tinh diem dua tren doi chieu dap an thi sinh chon
//      voi dap an dung tu file goc
//   3. Viet ham IN RA bang tong ket chi tiet sau khi thi xong:
//        - Diem tren thang 10
//        - So cau dung
//        - Thoi gian lam bai
//        - Hoi co muon xem lai bai khong

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

	friend ostream& operator<<(ostream& os, const result_calculator& calc);  //Nạp chồng toán tử xuất Overloading
public:
	// Constructor
	result_calculator();

	//1.Bộ đêm thời gian khi bắt đầu làm bài
	void startTimer();

	//Trả kết quả so s kể từ khi bâm làm bài
	long getElapsedSeconds();

	//2. Viet ham tinh diem dua tren doi chieu dap an thi sinh chon voi dap an dung tu file goc, luu trong AnswerManager, dap an dung (luu trong tung Question)
	void calculateScore(vector<Question> questions, AnswerManager answerMgr);

	//3.Viet ham IN RA bang tong ket chi tiet sau khi thi xong:
	void showResult(string candidateName, vector<Question> questions, AnswerManager answerMgr);


};

//OPERATOR OVERLOADING
ostream& operator<<(ostream& os, const result_calculator& calc);
