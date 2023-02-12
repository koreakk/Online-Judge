#include <bits/stdc++.h>
using namespace std;

queue<int> q;

void push  () { int x; cin >> x; q.push(x); }
void pop   () { if ( q.empty() ) { cout << "-1\n"; } else { cout << q.front() << '\n'; q.pop(); } }
void size  () { cout << q.size()       << '\n'; }
void empty () { cout << (int)q.empty() << '\n'; }
void front () { if ( q.empty() ) { cout << "-1\n"; } else { cout << q.front() << '\n'; } }
void back  () { if ( q.empty() ) { cout << "-1\n"; } else { cout << q.back()  << '\n'; } }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i ) {
        string str;
        cin >> str;

        if      ( str == "push"  ) { push();  }
        else if ( str == "pop"   ) { pop();   }
        else if ( str == "size"  ) { size();  }
        else if ( str == "empty" ) { empty(); }
        else if ( str == "front" ) { front(); }
        else if ( str == "back"  ) { back();  }
    }

    return 0;
}
