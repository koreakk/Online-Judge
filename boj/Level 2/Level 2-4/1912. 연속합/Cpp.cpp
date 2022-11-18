#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    
    int maxValue  = -1000;
    int currValue = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        
        maxValue  = max(maxValue, currValue + x);
        currValue = max(currValue + x, 0);
    }
    
    cout << maxValue << endl;
    return 0;
}