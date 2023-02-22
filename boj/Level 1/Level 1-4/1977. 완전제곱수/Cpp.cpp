 #include <bits/stdc++.h>
using namespace std;

int A[10001];

int main() {
    for (int i = 1; i <= 100; ++i) {
        A[i*i] = 1;
    }
    
    int M, N;
    cin >> M >> N;
    
    int mn = INT_MAX, sm = 0;
    
    for (int i = M; i <= N; ++i) {
        if (A[i] == 0) { continue; }
        
        mn = min(mn, i);
        sm += i;
    }
    
    if (sm == 0) { cout << "-1\n"; }
    else         { cout << sm << ' ' << mn << '\n'; }
    
    return 0;
}
