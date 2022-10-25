#include <iostream>
using namespace std;

int main() {
    int nums[3];
    for (int &num: nums) {
        cin >> num;
    }

    int result = nums[0] + nums[2] + nums[1] * 3 + 91;
    cout << "The 1-3-sum is " << result << endl;

    return 0;
}