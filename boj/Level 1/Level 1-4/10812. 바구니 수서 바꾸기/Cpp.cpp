#include <bits/stdc++.h>
using namespace std;

int A[100], T[100], N, M;

int main() {
   cin >> N >> M;

   for (int i = 0; i < N; ++i) { A[i] = i+1; }

   while (M--) {
        int b, e, m;
        cin >> b >> e >> m;

        int i = b-1;
        for (int j = m-1; j < e  ; ++j) { T[i++] = A[j]; }
        for (int j = b-1; j < m-1; ++j) { T[i++] = A[j]; }
        for (int j = b-1; j < e  ; ++j) { A[j]   = T[j]; }
   }

   for (int i = 0; i < N; ++i) { cout << A[i] << ' '; }
   cout << '\n';

   return 0;
}
