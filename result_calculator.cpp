 #include "result_calculator.h"
#include <iostream>
#include <cstring>
#include <algorithm>

// Constructor
result_calculator::result_calculator()
{
	startTime = 0; //Chưa bâm giờ
	correctCount = 0; //Chưa làm
	score = 0.0; //
	reportCandidateName = "";
	reportTotalQuestions = 0;
}



//1.Bộ đêm thời gian khi bắt đầu làm bài
void result_calculator::startTimer()
{
	startTime = time(nullptr);
}

//Trả kết quả so s kể từ khi bâm làm bài,  Tinh so giay da troi qua tu luc bam gio den hien tai
long result_calculator::getElapsedSeconds()
{
	time_t now = time(nullptr);  // thoi diem HIEN TAI (luc goi ham nay)
	return (long)(now - startTime);
}

//2. Viet ham tinh diem dua tren doi chieu dap an thi sinh chon voi dap an dung tu file goc, luu trong AnswerManager, dap an dung (luu trong tung Question)
//Dung STL ALGORITHM (Chuong 6) de dem so cau dung
void result_calculator::calculateScore(vector<Question> questions, AnswerManager answerMgr)
{
	correctCount = (int)count_if(questions.begin(), questions.end(), [&](const Question& q)
		{
			return  answerMgr.getAnswer(q.getId()) == q.getCorrectAnswer();
		});

	// Tinh diem theo thang 10:
   //  diem = (so cau dung / tong so cau) * 10

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
void result_calculator::showResult(string candidateName, vector<Question> questions, AnswerManager answerMgr)
{
	reportCandidateName = candidateName; // Luu lai thong tin de dung khi in (vi cac bien nay la thanh vien
	reportTotalQuestions = (int)questions.size(); // cua class, dung chung cho ca operator<< ben duoi)

	char timeBuffer[26];
	ctime_s(timeBuffer, sizeof(timeBuffer), &startTime); //ctime_s() doi gia tri time_t (startTime) thanh chuoi ngay-gio de

	cout << "           KET QUA THI" << endl;
	cout << "Candidate's name       : " << reportCandidateName << endl;
	cout << "Test start time      : " << timeBuffer;
	cout << "Test duration: " << getElapsedSeconds() << " giay" << endl;
	cout << "Number of correct answers     : " << correctCount << "/" << reportTotalQuestions << endl;
	cout << "Score             : " << score << "/10" << endl;

	//Hoi co muon xem lai bai khong 
	cout << "Do the candidates wish to review their work? [y/n]";
	char choice;
	cin >> choice;

	if (choice != 'y' && choice != 'Y') {
		return; // thi sinh khong muon xem lai -> ket thuc ham tai day
	}

	// In chi tiet tung cau (neeuss thí sinh chọn  "y") 
	cout << "\n----- CHECK YOUR ANSWER -----" << endl;
	for (int i = 0; i < (int)questions.size(); i++)
	{
		Question q = questions[i];
		char chosen = answerMgr.getAnswer(q.getId());
		cout << "\n Câu " << q.getId() << ": " << q.getQuestionText() << endl;

		if (chosen == '\0')
		{
			cout << "You didn't answer this question." << endl;
		}

		else if (chosen == q.getCorrectAnswer())
		{
			cout << "  Your choice: " << chosen << "  -> CORRECT" << endl;
		}
		else
		{
			cout << "  Your choice: " << chosen << "  -> INCORRECT (Correct answer: "
				<< q.getCorrectAnswer() << ")" << endl;
		}


	}
}



//OPERATOR OVERLOADING
ostream& operator<<(ostream& os, const result_calculator& calc)
{
	os << "[ResultCalculator] Thi sinh: " << calc.reportCandidateName
		<< ", So cau dung: " << calc.correctCount
		<< ", Diem: " << calc.score << "/10";
	return os;
}


