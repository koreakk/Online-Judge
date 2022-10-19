#include <stdbool.h>

#define INT(x)  ((x) - ('a'))

bool isAnagram(char * s, char * t){
    int Counter[26] = { 0, };

    for (int i = 0; s[i] != '\0'; i++)
        Counter[INT(s[i])]++;

    for (int i = 0; t[i] != '\0'; i++)
        Counter[INT(t[i])]--;

    for (int i = 0; i < 26; i++) {
        if (Counter[i] != 0)
            return false;
    }

    return true;
}
