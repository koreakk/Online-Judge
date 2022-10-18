#include <stdio.h>
#define MAXLEN  100

int solution(const char* string) {
    int len = -1;
    while (string[++len] != '\0') {}
    return len;
}


int main(void) {
    char string[MAXLEN];
    gets(string);

    printf("%d\n", solution(string));
    return 0;
}