#include <iostream>
using namespace std;

long long solution(int n) {
	long long Tmp = 0;
	long long x = 0, y = 1, z = 1;

	for (int i = 0; i < n; ++i) {
		Tmp = x + z;
		x   = y;
		y   = z;
		z   = Tmp;
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