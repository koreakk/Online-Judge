#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {

    string options = "RTCFJMAN";
    int table[8]   = { 0 };
    auto ref = [&table, options](char option) -> int& {
        for (int i = 0; i < 8; ++i) {
            if (options[i] == option) {
                return table[i];
            }
        }
    };

    const size_t length = survey.size();
    for (size_t i = 0; i < length; ++i) {
        string option = survey[i];
        int choice    = choices[i];

        if (choice > 4) {
            ref(option[1]) += choice - 4;
        } else if (choice < 4) {
            ref(option[0]) += 4 - choice;
        }
    }
    
    string answer = "";
    for (int i = 0; i < 8; i += 2) {
        if (table[i] >= table[i + 1]) {
            answer += options[i];
        } else {
            answer += options[i + 1];
        }
    }

    return answer;
}