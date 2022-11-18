#include <stdio.h>
#include <stdbool.h>

#define SWAP(A, B)  \
((A) ^= (B));       \
((B) ^= (A));       \
((A) ^= (B))

#define MAX(A, B, C)    \
if ((A) < (B)) {SWAP(A, B);}  \
if ((C) < (A)) {SWAP(C, A);}

bool isRightTriangle(int a, int b, int c) {
    MAX(a, b, c)

    return (a * a) + (b * b) == (c * c);
}

int main(void) {
    int a, b, c;

    while (true) {
        scanf("%d %d %d", &a, &b, &c);

        if (!(a || b || c)) break;
        puts(isRightTriangle(a, b, c) ? "right" : "wrong");
    }
}