#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(A, B)   ((A) > (B)) ? (A) : (B)

int dp[41][41];

char* solution(const char* word_A, const char* word_B) {
    int A_len = strlen(word_A);
    int B_len = strlen(word_B);

    for (int i = 1; i <= B_len; i++) {
        for (int j = 1; j <= A_len; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (word_B[i - 1] == word_A[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int x = A_len, y = B_len;
    int res_len = dp[y][x];
    char* res = (char*)malloc(sizeof(char) * (res_len + 1));
    res[res_len] = '\0';

    while (dp[y][x]) {
        if (dp[y][x] == dp[y][x - 1])
            x--;
        else if (dp[y][x] == dp[y - 1][x])
            y--;
        else {
            x--, y--;
            res[--res_len] = word_A[x];
        }
    }

    return res;
}

int main(void) {
    char word_A[41], word_B[41];
    scanf("%s %s", word_A, word_B);

    char* res = solution(word_A, word_B);
    printf("%s\n", res);

    free(res);
    return 0;
}