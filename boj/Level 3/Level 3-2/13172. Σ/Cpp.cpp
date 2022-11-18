#include <iostream>
using namespace std;

typedef long long ll;

ll pow(ll base, ll exp, ll mod) {
    ll result = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    ll mod = 1000000007;
    
    int M;
    cin >> M;

    ll result = 0;
    for (int i = 0; i < M; ++i) {
        ll N, S;
        cin >> N >> S;
        result = (result + pow(N, mod - 2LL, mod) * (S % mod)) % mod;
    }

    cout << result << endl;
    return 0;
}