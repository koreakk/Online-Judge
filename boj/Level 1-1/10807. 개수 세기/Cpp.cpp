#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (auto &num : nums) {
        cin >> num;
    }
    
    int target;
    cin >> target;
    
    cout << count(nums.begin(), nums.end(), target) << endl;
    
    return 0;
}