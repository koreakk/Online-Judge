#include <bits/stdc++.h>
using namespace std;

int main(void) {
	array<int, 5> nums;
	for (auto &n: nums) {
		cin >> n;
		if (n < 40) {
			n = 40;
		}
	}
	
	cout << accumulate(nums.begin(), nums.end(), 0) / 5 << endl;
	return 0;
}