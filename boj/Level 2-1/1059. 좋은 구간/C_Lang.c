#include <stdio.h>

int solution(int L, int* S, int n) {
    int min_num = 1;
    int max_num = 1000;

    for (int i = 0; i < L; i++) {
        if (S[i] == n) return 0;

        if (S[i] < n)
            min_num = (min_num > S[i] + 1) ? min_num : S[i] + 1;

        else if (S[i] > n)
            max_num = (max_num < S[i] - 1) ? max_num : S[i] - 1;
    }

    return (max_num - n + 1) * (n - min_num) + (max_num - n);
}

int main(void) {
    int L, S[50], n;

    scanf("%d", &L);
    for (int i = 0; i < L; i++)
        scanf("%d", S + i);
    scanf("%d", &n);

    printf("%d\n", solution(L, S, n));
    return 0;
}