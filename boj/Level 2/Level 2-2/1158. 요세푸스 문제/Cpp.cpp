#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> dq(n);
    for (int i=0; i<n; ++i) { dq[i]=i+1; }

    cout << "<";
    while(!dq.empty()) {
        for (int i=0; i<k; ++i) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout << dq.back();
        dq.pop_back();

        if (!dq.empty()) {
            cout << ", ";
        }
    }
    cout << ">\n";

    return 0;
}
