#include <stdio.h>
#include <string.h>
#define MAXLEN      1000

int main(void) {
    char a[MAXLEN], b[MAXLEN];

    scanf("%s", a), scanf("%s", b);
    printf(strlen(a) < strlen(b) ? "no" : "go");
    return 0;
}