#include <iostream>
using namespace std;
using ull = unsigned long long;

ull powmod(__int128 n, __int128 r, __int128 m) {
    ull ret = 1;
    while (r) {
        if (r & 1) {
            ret = (ret * n) % m;
        }
        n = (n * n) % m;
        r >>= 1;
    }
    return (ull)ret;
}

bool miller_rabin_primality_test(ull n, ull a) {
    ull d = n - 1;
    ull r = 0;

    while (!(d & 1)) {
        d >>= 1;
        ++r;
    }
    
    ull x = powmod(a, d, n);
    if (x == 1 || x == n-1) {
        return true;
    }

    while (--r) {
        x = powmod(x, 2, n);
        if (x == 1) {
            return false;
        }
        if (x == n - 1) {
            return true;
        }
    }

    return false;
}

bool is_prime(ull n) {
    if (n < 10) {
        for (ull p : {2, 3, 5, 7}) {
            if (n == p) {
                return true;
            }
        }
        return false;
    }

    if (!(n & 1)) {
        return false;
    }

    for (ull a : {2, 3, 5, 7, 11}) {
        if (n == a) { 
            return true; 
        }
        if (!miller_rabin_primality_test(n, a)) {
            return false;
        }
    }
    return true;
}

ull reverse_number(ull n) {
    ull ret = 0;
    while (n) {
        ret *= 10;
        ret += (n % 10);
        n /= 10;
    }
    return ret;
}

int main() {
    ull l, h;
    cin >> l >> h;

    ull cnt = 0;
    ull d = 1, p;
    for (ull i = 1; i < 1000000; ++i) {
        if (d <= i / 10) { d *= 10; }
        
        p = d * i + reverse_number(i / 10);
        if (l <= p && p <= h && is_prime(p)) {
            ++cnt;
        }
        
        p = 10 * d * i + reverse_number(i);
        if (l <= p && p <= h && is_prime(p)) {
            ++cnt;
        }
    }

    cout << cnt << '\n';
    return 0;
}