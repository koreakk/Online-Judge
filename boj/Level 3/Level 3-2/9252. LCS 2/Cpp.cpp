#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

string LCS(const string& x, const string& y) {
    const size_t xSize = x.size();
    const size_t ySize = y.size();

    vector<vector<int>> dp(xSize + 1, vector<int>(ySize + 1, 0));
    for (size_t i = 1; i <= xSize; ++i) {
        for (size_t j = 1; j <= ySize; ++j) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    size_t i = xSize, j = ySize;
    string result;

    while (dp[i][j]) {
        if (max(dp[i - 1][j], dp[i][j - 1]) < dp[i][j]) {
            result = x[i - 1] + result;
            --i, --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    return result;
}

void solve() {
    string A, B;
    cin >> A >> B;
    
    string result = LCS(A, B);
    cout << result.size() << endl;
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}