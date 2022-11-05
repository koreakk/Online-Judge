#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        auto lenght = s.length();
        
        if (lenght < 6 || lenght > 9) {
            cout << "no"  << endl;
        } else {
            cout << "yes" << endl;
        }
    }
    
    return 0;
}