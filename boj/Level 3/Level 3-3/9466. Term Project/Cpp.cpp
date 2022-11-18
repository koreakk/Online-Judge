#include <bits/stdc++.h>
using namespace std;

int N, arr[100000], visited[100000];

pair<int, int> dfs(int x, int cnt=1) {
    if (visited[x]) {
        return { cnt - visited[x], x};
    }

    visited[x] = cnt;
    auto [result, parent] = dfs(arr[x] - 1, cnt + 1);
    if (x == parent) parent = -1;
    
    return { result, parent };
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    memset(visited, 0, sizeof(visited));
    int result = N;
    for (int i = 0; i < N; ++i) {
        if (visited[i] == 0) {
            auto [r, p] = dfs(i);
            if (p == -1) {
                result -= r;
            }
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}