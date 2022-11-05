#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int score(int A, int scores[]) {
    int res = 0;
    for (int i = 0; i <= 10; i++) {
        if (A & (1 << i))
            res += scores[i];
    }

    return res;
}

bool compare(int A, int B) {
    for (int i = 0; i <= 10; i++) {
        if ((A & (1 << i)) > (B & (1 << i)))
            return true;

        else if ((A & (1 << i)) < (B & (1 << i)))
            return false;
    }
    return true;
}

// info_len은 배열 info의 길이입니다.
int* solution(int n, int info[], size_t info_len) {
    // 라이언이 얻을 수 있는 점수 계산 오름차순으로 저장 ( info 는 내림차순 )
    int scores[11] = { 0, };
    int relative_score = 0;

    for (int i = 0; i < info_len; i++) {
        scores[i] = i;

        // 어피치가 점수를 얻은 경우 가치가 2배 증가한다. (라이언 점수 + 어피치 점수)
        if (info[info_len - i - 1] >= 1) {
            scores[i] *= 2;
            relative_score += i;
        }
    }

    // dp를 이용한 문제 해결
    int dp[12][11] = { 0, };
    int con = 0;
    int A = 0, B = 0;
    int scoreA = 0;
    int scoreB = 0;

    for (int i = 1; i <= info_len; i++) {
        con = info[info_len - i] + 1;

        for (int j = 1; j <= n; j++) {
            if (con <= j) {
                A = dp[i - 1][j - con] | (1 << (i-1));
                B = dp[i - 1][j];

                scoreA = score(A, scores);
                scoreB = score(B, scores);

                if (scoreA > scoreB || (scoreA == scoreB && compare(A, B))) {
                    dp[i][j] = A;
                }
                else {
                    dp[i][j] = B;
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int result = dp[info_len][n];

    if (relative_score >= score(result, scores)) {
        int* answer = (int*)malloc(sizeof(int));
        *answer = -1;
        return answer;
    }

    int* answer = (int*)malloc(sizeof(int) * info_len);

    int total = 0;
    for (int i = 0; i < info_len; i++) {
        answer[i] = 0;

        if (result & (1 << (info_len - i - 1))) {
            answer[i] = info[i] + 1;
            total += answer[i];
        }
    }
    answer[info_len - 1] += n - total;

    return answer;
}
