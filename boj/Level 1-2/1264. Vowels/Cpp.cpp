#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string vowels = "AEIOUaeiou";
    
    while (true) {
        string str;
        getline(cin, str);
        
        if (str == "#") {
            break;
        }
        
        int count = 0;
        for (auto c : str) {
            for (auto v : vowels) {
                if (c == v) {
                    ++count;
                    break;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}