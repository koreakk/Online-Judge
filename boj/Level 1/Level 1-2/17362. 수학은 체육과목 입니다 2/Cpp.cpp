#include <iostream>
using namespace std;

int main() {
    int A[8] = { 2, 1, 2, 3, 4, 5, 4, 3 };
    int n;
    cin >> n;
    cout << A[n % 8] << '\n';
    return 0;
}