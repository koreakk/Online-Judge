#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void combinations(const string& s, int r, map<string, int>& table) {
    auto Add = [&](const vector<int>& indices) {
        string ans;
        for (int i : indices) {
            ans += s[i];
        }

        ++table[ans];
    };

    auto F = [](const vector<int>& indices, int n) {
        int r = indices.size();
        for (int i = r - 1; i >= 0; --i) {
            if (indices[i] != i + n - r) {
                return i;
            }
        }
        return -1;
    };

    int n = s.size();
    if (r > n) {
        return;
    }

    vector<int> indices(r);
    for (int i = 0; i < r; ++i) {
        indices[i] = i;
    }
    Add(indices);
    while (true) {
        int i = F(indices, n);
        if (i == -1) {
            return;
        }

        ++indices[i];
        for (int j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
        Add(indices);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (string &s : orders) {
        sort(s.begin(), s.end());
    }
    
    vector<string> answer;
    for (int r : course) {
        map<string, int> table;
        for (const string& s : orders) {
            combinations(s, r, table);
        }
        
        int maxSub = 0;
        for (const auto& [s, r] : table) {
            maxSub = max(maxSub, r);
        }
        
        for (const auto& [s, r] : table) {
            if (r >= 2 && r == maxSub) {
                answer.push_back(s);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}