#include <iostream>
#include <string>
using namespace std;

int main() {
    int A[26] = { 0 };
    char c;

    while ((c = getchar()) != EOF) {
        if ('a' <= c && 'z' >= c) {
            ++A[c - 'a'];
        }
    }

    int max_count = 0;
    for (int i = 0; i < 26; ++i) {
        max_count = max(max_count, A[i]);
    }

    for (int i = 0; i < 26; ++i) {
        if (A[i] == max_count) {
            cout << (char)(i + 'a');
        }
    }
    cout << '\n';

    return 0;
}