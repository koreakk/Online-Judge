#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int solve(int src, int dest) {
    queue<ll> q;
    q.push(src);

    for (int count = 2; !q.empty(); ++count) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            ll num = q.front();
            q.pop();

            ll next1 = num * 2;
            ll next2 = (num * 10) + 1;
            
            if (next1 == dest || next2 == dest) {
                return count;
            }
            
            if (next1 < dest) {
                q.push(next1);
            }
            if (next2 < dest) {
                q.push(next2);
            }
        }
    }

    return -1;
}

int main() {
    int A, B;
    cin >> A >> B;

    cout << solve(A, B) << endl;
    return 0;
}
