#include <iostream>
using namespace std;

long long solution(int n) {
	const auto mod = 1000000007;

	long long Tmp = 0;
	long long x = 1, y = 1;

	for (int i = 0; i < n; ++i) {
		Tmp = (x + y + 1) % mod;
		x   = y;
		y   = Tmp;
	}

	return x;
}

int main(void)
{
	int n;
	cin >> n;

	cout << solution(n) << endl;
	return 0;
}