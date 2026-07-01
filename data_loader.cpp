#include "data_loader.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

vector<Question> DataLoader::loadData(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "[Lỗi] Không thể mở file dữ liệu!" << endl;
        return questions;
    }

    int totalQuestions;
    if (file >> totalQuestions) {
        file.ignore(1000, '\n');
    }
    
    int q_id;
    while (file >> q_id) {
        

        string q_text;
        getline(file, q_text);

        int num_options;
        file >> num_options;
        file.ignore(1000, '\n');

        vector<string> q_options;
        string line_options;
        if (getline( file, line_options)){ 
            stringstream ss(line_options);
            string options;
            while (ss >> options ){
                q_options.push_back(options);
            }
        }
        char q_answer;
        file >> q_answer;
        file.ignore(1000, '\n');

        questions.push_back(Question(q_id, q_text, q_options, q_answer));
    }

    file.close();
    return questions;
}
