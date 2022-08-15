#include <stdbool.h>

#define INT(x)  ((x) - ('a'))

bool canConstruct(char * ransomNote, char * magazine) {
    int Counter[26] = { 0, };

    for (int i = 0; magazine[i] != '\0'; i++)
        Counter[INT(magazine[i])]++;

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (Counter[INT(ransomNote[i])]-- == 0)
            return false;
    }

    return true;
}