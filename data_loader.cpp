#include "data_loader.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

vector<Question> DataLoader::loadData(const string& filename) {
    vector<Question> questions;
    ifstream file(filename); 

    if (!file.is_open()) {
        cerr << "[Lỗi] Không thể mở file dữ liệu: " << filename << endl;
        return questions;
    }

    string line;
    
    while (getline(file, line)) {
        line = trim(line);
        if (line.empty()) continue;
        if (isdigit(line[0]) && line.find("-->") == string::npos) {
            break; 
        }
    }

    while (!file.eof() && !line.empty()) {
        stringstream ss(line); 
        int q_id;
        ss >> q_id; 
        
        string q_text;
        getline(ss, q_text);
        q_text = trim(q_text); 

        getline(file, line); 
        line = trim(line);
        if (line.find("-->") != string::npos || (line.size() == 1 && isdigit(line[0]))) {
            getline(file, line);
            line = trim(line);
        }

        vector<string> q_options;
        stringstream option_ss(line);
        string single_option;
        while (option_ss >> single_option) {
            q_options.push_back(single_option);
        }

        char q_answer = ' ';
        if (getline(file, line)) {
            line = trim(line);
            if (!line.empty()) {
                q_answer = tolower(line[0]); 
            }
        }

        questions.push_back(Question(q_id, q_text, q_options, q_answer));

        while (getline(file, line)) {
            line = trim(line);
            if (!line.empty()) break; 
        }
    }

    file.close();
    return questions;
}

void DataLoader::printQuestions(const vector<Question>& questions) {
    cout << "============= KẾT QUẢ BÓC TÁCH DỮ LIỆU FILE =============" << endl;
    for (const auto& q : questions) {
        cout << "Câu hỏi số: " << q.getId() << endl;
        cout << "Nội dung:   " << q.getQuestionText() << endl;
        cout << "Danh sách đáp án (vector):" << endl;
        
        auto opts = q.getOptions();
        for (size_t i = 0; i < opts.size(); ++i) {
            cout << "  [" << (char)('a' + i) << "] " << opts[i] << endl;
        }
        cout << "=> Ký tự đáp án đúng bóc tách được: " << q.getCorrectAnswer() << endl;
        cout << "--------------------------------------------------------" << endl;
    }
}
