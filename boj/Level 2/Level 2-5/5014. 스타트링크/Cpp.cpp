#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int A[1000001];

int main() {
    cin >> F >> S >> G >> U >> D;

    queue<int> q;
    q.push(S);
    A[S] = 1;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (i+U <= F && !A[i+U]) {
            A[i+U] = A[i] + 1;
            q.push(i+U);
        }

        if (i-D >= 1 && !A[i-D]) {
            A[i-D] = A[i] + 1;
            q.push(i-D);
        }
    }

    if (A[G]) {
        cout << A[G]-1 << '\n';
    }
    else {
        cout << "use the stairs\n";
    }

    return 0;
}
