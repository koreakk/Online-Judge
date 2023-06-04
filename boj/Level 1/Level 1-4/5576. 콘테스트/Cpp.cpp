#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int W[10], K[10];

	for_each(W, W + 10, [](int& p) { cin >> p; });
	for_each(K, K + 10, [](int& p) { cin >> p; });

	sort(W, W + 10, greater<>{});
	sort(K, K + 10, greater<>{});

	int wret = accumulate(W, W + 3, 0);
	int kret = accumulate(K, K + 3, 0);

	cout << wret << ' ';
	cout << kret << '\n';

	return 0;
}