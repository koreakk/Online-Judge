#include <iostream>
#include <deque>
using namespace std;

int dp[44] = { 1, 1 };

void solution(int n) {
	deque<int> res;

	for (int i = 43; n; --i) {
		if (n >= dp[i]) {
			n -= dp[i];
			res.emplace_front(dp[i]);
		}
	}

	for (const auto& n : res) {
		cout << n << ' ';
	}
	cout << endl;
}

int main(void)
{
	for (int i = 2; i < 44; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int TestCase;
	cin >> TestCase;

	for (int i = 0; i < TestCase; ++i) {
		int n;
		cin >> n;

		solution(n);
	}

	return 0;
}
