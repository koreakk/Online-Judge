#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve(int n, int k) {
    if (n >= k) {
        cout << n - k << endl;
        cout << 1     << endl;
        return;
    }

    vector<int> dist(k + 2);
    vector<int> counter(k + 2);
    counter[n] = 1;
    
    queue<int> q;
    q.emplace(n);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : { curr + 1, curr - 1, curr * 2 }) {
            if (next < 0 || next > k + 1) {
                continue;
            }
            
            if (!dist[next]) {
                dist[next]     = dist[curr] + 1;
                counter[next] += counter[curr];
                q.push(next);
            }
            else if (dist[next] == dist[curr] + 1) {
                counter[next] += counter[curr];
            }
        }
    }

    cout << dist[k]    << endl;
    cout << counter[k] << endl;
}

int main() {
    int N, K;
    cin >> N >> K;

    solve(N, K);
    return 0;
}