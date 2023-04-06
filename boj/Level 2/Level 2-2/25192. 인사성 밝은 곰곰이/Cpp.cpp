#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> st;
    string name;
    int ret = 0;

    while (n--) {
        cin >> name;

        if (name == "ENTER") {
            ret += st.size();
            st.clear();
        }
        
        else {
            st.insert(name);
        }
    }
    ret += st.size();
    
    cout << ret << '\n';
}
