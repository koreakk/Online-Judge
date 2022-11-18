#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 100000000

vector<vector<int>> combinations(int n, int r) {
    vector<vector<int>> result;
    if (r > n) return result;

    vector<int> indices(r);
    for (int i = 0; i < r; ++i) {
        indices[i] = i;
    }

    result.emplace_back(indices);
    while (true) {
        int i = -1;
        for (int j = r - 1; j >= 0; --j) {
            if (indices[j] != j + n - r) {
                i = j;
                break;
            }
        }
        if (i == -1) break;

        ++indices[i];
        for (int j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
        result.emplace_back(indices);
    }

    return result;
}

int solve(const vector<pair<int, int>>& home, const vector<pair<int, int>>& dest, int m) {
    const int homeSize = (int)home.size();
    const int destSize = (int)dest.size();

    vector<vector<int>> distInfo(homeSize);
    for (int i = 0; i < homeSize; ++i) {
        const auto& [homeX, homeY] = home[i];

        distInfo[i].resize(destSize);
        for (int j = 0; j < destSize; ++j) {
            const auto& [destX, destY] = dest[j];
            distInfo[i][j] = abs(homeX - destX) + abs(homeY - destY);
        }
    }

    int result = INF;    
    for (const auto& currCombinations : combinations(destSize, m)) {
        int res = 0;
        for (int i = 0; i < homeSize; ++i) {
            int minDist = INF;
            for (int destIdx : currCombinations) {
                minDist = min(minDist, distInfo[i][destIdx]);
            }
            res += minDist;
        }
        result = min(result, res);
    }
   
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> home;
    vector<pair<int, int>> dest;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int state;
            cin >> state;

            switch (state) {
            case 1:
                home.emplace_back(i, j);
                break;
            case 2:
                dest.emplace_back(i, j);
                break;
            default:
                break;
            }
        }
    }

    cout << solve(home, dest, M) << endl;
    return 0;
}
