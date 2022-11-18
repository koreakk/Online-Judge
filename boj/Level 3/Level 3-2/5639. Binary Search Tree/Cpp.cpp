#include<iostream>
#include<vector>
using namespace std;

template<class iter>
void solve(iter first, iter last) {
    if (first == last)
        return;

    iter left = first + 1;
    iter right = first;
    for (; right != last && *right <= *first; ++right) {}

    solve(left, right);
    solve(right, last);
    cout << *first << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int node;
    while (cin >> node)
        v.push_back(node);

    solve(v.begin(), v.end());
    return 0;
}