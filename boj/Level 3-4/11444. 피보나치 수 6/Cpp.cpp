//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Matrix_2x2
{
	using value_type = unsigned long long;

	value_type mat[2][2] = { 0, };

	Matrix_2x2 operator^(long long exponent) {
		Matrix_2x2 result = {1, 0, 0, 1};
		Matrix_2x2 base   = *this;
		
		for (; exponent > 0; exponent /= 2) {
			if (exponent % 2 != 0) {
				result = base * result;
			}

			base *= base;
		}

		return result;
	}

	Matrix_2x2 operator*(Matrix_2x2& rhs) {
		Matrix_2x2 result;

		auto& newMat = result.mat;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					newMat[i][j] += mat[i][k] * rhs.mat[k][j];
				}

				newMat[i][j] %= 1000000007;
			}
		}

		return result;
	}

	Matrix_2x2& operator*=(Matrix_2x2& rhs) {

		*this = this->operator*(rhs);
		
		return *this;
	}
};

unsigned long long solution(long long n) {
	if (n == 0) {
		return 0;
	}

	Matrix_2x2 base = { 1, 1, 1, 0 };
	return (base ^ (n - 1)).mat[0][0];
}

int main(void)
{
	long long n;
	cin >> n;

	cout << solution(n) << endl;
	return 0;
}