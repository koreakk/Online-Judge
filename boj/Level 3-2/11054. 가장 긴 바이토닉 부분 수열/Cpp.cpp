#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1050][2];

int solve(int N, const vector<int>& A) {
    for (int i = 0; i < N; ++i) {
        int currNum = A[i];

        for (int j = 0; j < i; ++j) {
            if (currNum > A[j]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }

            else if (currNum < A[j]) {
                dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]) + 1);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        answer = max(answer, max(dp[i][0], dp[i][1]));
    }

    return answer + 1;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int& x : A) {
        cin >> x;
    }

    cout << solve(N, A) << endl;
    return 0;
}