#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    int nextMaxCache[3];
    int nextMinCache[3];
    
    int maxCache[3] = { 0 };
    int minCache[3] = { 0 };

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> nextMaxCache[j];
            nextMinCache[j] = nextMaxCache[j];
        }
        
        for (int j = 0; j < 3; ++j) {
            int maxNum = INT_MIN, minNum = INT_MAX;

            for (int k = j - 1; k <= j + 1; ++k) {
                if (k < 0 || k >= 3) continue;

                maxNum = max(maxNum, maxCache[k]);
                minNum = min(minNum, minCache[k]);
            }

            nextMaxCache[j] += maxNum;
            nextMinCache[j] += minNum;
        }

        for (int j = 0; j < 3; ++j) {
            maxCache[j] = nextMaxCache[j];
            minCache[j] = nextMinCache[j];
        }
    }

    int maxResult = max(max(maxCache[0], maxCache[1]), maxCache[2]);
    int minResult = min(min(minCache[0], minCache[1]), minCache[2]);

    cout << maxResult << ' '
         << minResult << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
