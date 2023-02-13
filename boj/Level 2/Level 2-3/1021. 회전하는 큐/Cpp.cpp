#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq(N);
    for (int i = 0; i < N; ++i) {
        dq[i] = i+1;
    }

    int ret = 0;
    while (M--) {
        int x;
        cin >> x;

        int count = 0;
        while (dq.front() != x) {
            dq.push_back(dq.front());
            dq.pop_front();

            ++count;
        }

        dq.pop_front();
        ret += min(count, (int)dq.size() - count + 1);
    }

    cout << ret << '\n';
    return 0;
}
