#define INT(x)  ((x) - ('a'))

int firstUniqChar(char * s) {
    int Counter[26] = { 0, };

    int i = -1;
    while (s[++i] != '\0')
        Counter[INT(s[i])] += 1;

    i = -1;
    while (s[++i] != '\0') {
        if (Counter[INT(s[i])] == 1)
            return i;
    }

    return -1;
}