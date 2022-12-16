#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

class matrix_8x8 {
public:
    ll* operator[](int i) {
        return mat[i];
    }

    const ll* operator[](int i) const {
        return mat[i];
    }

private:
    ll mat[8][8] = { 0 };
};

matrix_8x8 multiply(const matrix_8x8& l, const matrix_8x8& r, ll mod) {
    matrix_8x8 ret;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                ret[i][j] += (l[i][k] % mod) * (r[k][j] % mod);
                ret[i][j] %= mod;
            }
        }
    }

    return ret;
}

matrix_8x8 power(matrix_8x8 base, ll exp, ll mod) {
    matrix_8x8 ret;
    for (int i = 0; i < 8; ++i) {
        ret[i][i] = 1;
    }

    for (; exp; exp >>= 1) {
        if (exp & 1) {
            ret = multiply(base, ret, mod);
        }
        base = multiply(base, base, mod);
    }

    return ret;
}

void solve() {
    int N;
    cin >> N;

    ll m[8][8] = {
        { 0, 1, 1, 0, 0, 0, 0, 0 },
        { 1, 0, 1, 1, 0, 0, 0, 0 },
        { 1, 1, 0, 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 1, 0, 0 },
        { 0, 0, 1, 1, 0, 1, 1, 0 },
        { 0, 0, 0, 1, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 0 }
    };

    matrix_8x8 mat;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            mat[i][j] = m[i][j];
        }
    }

    cout << power(mat, N, MOD)[0][0] << '\n';
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}