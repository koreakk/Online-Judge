#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    int B;
    cin >> N >> B;

    int ret=0, j=1;
    for (int i=N.length()-1; i>=0; --i) {
        int d;
        if ('A'<=N[i] && N[i]<='Z') { d=N[i]-'A'+10; }
        else                        { d=N[i]-'0';    }

        ret+=d*j;
        j*=B;
    }

    cout << ret << '\n';
    return 0;
}
