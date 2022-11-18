#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int nums[9];
    int sum = 0;
    
    for (int &num : nums) {
        cin >> num;
        sum += num;
    }
    
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (nums[i] + nums[j] == sum - 100) {
                nums[i] = -1;
                nums[j] = -1;
                
                sort(nums, nums + 9);
                for (int i = 2; i < 9; ++i) {
                    cout << nums[i] << endl;
                }
                return 0;
            }
        }
    }
    
    
    return 0;
}