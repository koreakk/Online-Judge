#include <iostream>
using namespace std;

int main(void)
{
    int x, n;
    cin >> x >> n;
    
    for (int i = 0; i < n; ++i) {
        int price, count;
        cin >> price >> count;
        
        x -= price * count;
    }
    
    if (x == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No"  << endl;
    }
    
    return 0;
}