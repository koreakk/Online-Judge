#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

int main() {
	array<pair<int, int>, 8> A;
	for (int i = 0; i < 8; ++i) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A.begin(), A.end(), greater<>{});

	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += A[i].first;
	}

	sort(A.begin(), A.begin() + 5,
		[](pair<int, int> l, pair<int, int> r) {
			return l.second < r.second;
		});

	cout << sum << '\n';
	for (int i = 0; i < 5; ++i) {
		cout << A[i].second << ' ';
	}
	cout << '\n';
	return 0;
}