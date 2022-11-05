#include <iostream>
using namespace std;

int main(void) {
    int array[6];
    
    for (auto &n : array) {
        cin >> n;
    }    
    
    int result(0);
    for (auto n : array) {
        result += n * 5;
    }
    
    cout << result << endl;
    return 0;
}