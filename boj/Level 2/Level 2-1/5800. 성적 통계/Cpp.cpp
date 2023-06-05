#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A[100], t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		int k;
		cin >> k;

		for_each(A, A + k, [](int& p) { cin >> p; });
		sort(A, A + k);

		int Max = A[k - 1], Min = A[0];
		int LargestGap = 0;

		for (int j = 1; j < k; ++j) {
			LargestGap = max(LargestGap, A[j] - A[j - 1]);
		}

		printf("Class %d\n", i);
		printf("Max %d, Min %d, Largest gap %d\n",
			Max, Min, LargestGap);
	}
	return 0;
}