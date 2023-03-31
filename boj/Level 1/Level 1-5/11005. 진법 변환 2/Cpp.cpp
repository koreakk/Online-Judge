#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    string ret;
    for (; N; N/=B) {
        if (N%B>=10) { ret+=(char)(N%B-10+'A'); }
        else         { ret+=(char)(N%B+'0');    }
    }
    
    for (int i=0, j=ret.length()-1; i<j; ++i, --j) {
        swap(ret[i], ret[j]);
    }

    cout << ret << '\n';
    return 0;
}
