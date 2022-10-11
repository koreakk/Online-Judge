#include <iostream>
#include <vector>
using namespace std;

void PrintNumber(const vector<int>& x) {
	auto rend(x.crend());
	for (auto riter = x.crbegin(); riter != rend; ++riter) {
		cout << *riter;
	}
	cout << endl;
}

void Add(vector<int>& base, const vector<int>& x) {
	if (base.size() < x.size()) {
		base.resize(x.size(), 0);
	}

	const size_t length = base.size();
	
	int sum   = 0;
	int carry = 0;

	for (size_t i = 0; i < length; ++i) {
		sum = base[i] + x[i] + carry;

		base[i] = sum % 10;
		carry   = sum / 10;
	}
	if (carry != 0) {
		base.emplace_back(carry);
	}
}

vector<int> fib(long long n) {
	vector<int> x = { 0, }, y = { 1, };
	x.reserve(1000);
	y.reserve(1000);
	
	for (int i = 0; i < n; ++i) {
		Add(x, y);
		swap(x, y);
	}

	return x;
}

int main(void)
{
	int n;
	cin >> n;

	PrintNumber(fib(n));
	return 0;
}