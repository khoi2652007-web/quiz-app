#include "result_calculator.h"
#include <iostream>
#include <cstring>
#include <algorithm>

result_calculator::result_calculator()
{
	startTime = 0; //Chưa bâm giờ
	correctCount = 0; //Chưa làm
	score = 0.0; //
	reportCandidateName = "";
	reportTotalQuestions = 0;
}


void result_calculator::startTimer()
{
	startTime = time(nullptr);
}

long result_calculator::getElapsedSeconds() const
{
	time_t now = time(nullptr);  // thoi diem HIEN TAI (luc goi ham nay)
	return (long)(now - startTime);
}

//Dung STL ALGORITHM (Chuong 6) de dem so cau dung
void result_calculator::calculateScore(const vector<Question>& questions, const AnswerManager& answerMgr)
{
	correctCount = (int)count_if(questions.begin(), questions.end(), [&](const Question& q)
		{
			return  answerMgr.getAnswer(q.getId()) == q.getCorrectAnswer();
		});

 
	int total = (int)questions.size();
	if (total == 0)
	{
		score = 0.0;
	}
	else
	{
		score = (double)correctCount / total * 10.0;
	}

}

//3.Viet ham IN RA bang tong ket chi tiet sau khi thi xong:
void result_calculator::showResult(const string& candidateName, const vector<Question>& questions, const AnswerManager& answerMgr)
{	
	reportCandidateName = candidateName; // Luu lai thong tin de dung khi in (vi cac bien nay la thanh vien
	reportTotalQuestions = (int)questions.size(); // cua class, dung chung cho ca operator<< ben duoi)

	char timeBuffer[26];
	ctime_s(timeBuffer, sizeof(timeBuffer), &startTime); //ctime_s() doi gia tri time_t (startTime) thanh chuoi ngay-gio de

	cout << "           KET QUA THI" << endl;
	cout << "Thi sinh       : " << reportCandidateName << endl;
	cout << "Gio bat dau      : " << timeBuffer;
	cout << "Thoi gian lam bai	: " << getElapsedSeconds() << " giay" << endl;
	cout << "So cau dung     : " << correctCount << "/" << reportTotalQuestions << endl;
	cout << "Diem             : " << score << "/10" << endl; 

	cout << "\nBan co muon xem lai bai khong? (y = co, n = khong): ";
	char choice;
	cin >> choice;

	if (choice != 'y' && choice != 'Y') {
		return; // thi sinh khong muon xem lai -> ket thuc ham tai day
	}

	cout << "\n----- XEM LAI BAI LAM -----" << endl;
	for (int i = 0; i < (int)questions.size(); i++)
	{
		const Question& q = questions[i];
		char chosen = answerMgr.getAnswer(q.getId());
		cout << "\n Câu " << q.getId() << ": " << q.getQuestionText() << endl;

		if (chosen == ' ')
		{
			cout << "  Ban da KHONG tra loi cau nay." << endl;
		}

		else if (chosen == q.getCorrectAnswer())
		{
			cout << "  Ban chon: " << chosen << "  -> DUNG" << endl;
		}
		else
		{
			cout << "  Ban chon: " << chosen << "  -> SAI (Dap an dung la: "
				<< q.getCorrectAnswer() << ")" << endl;
		}


	}
}


ostream& operator<<(ostream& os, const result_calculator& calc)
{
	os << "[ResultCalculator] Thi sinh: " << calc.reportCandidateName
		<< ", So cau dung: " << calc.correctCount
		<< ", Diem: " << calc.score << "/10";
	return os;
}


