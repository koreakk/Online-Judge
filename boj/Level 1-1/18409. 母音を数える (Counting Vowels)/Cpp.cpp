#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int result = 0;
    for (char c : s) {
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            ++result;
        }
    }
    
    cout << result << endl;
    return 0;
}