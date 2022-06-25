#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {

    int rank[] = { 6, 6, 5, 4, 3, 2, 1 };

    int cnt_0 = 0;
    int ans = 0;

    for (int i = 0; i < lottos_len; i++) {
        if (lottos[i] == 0) {
            cnt_0++;
            continue;
        }

        for (int j = 0; j < win_nums_len; j++) {
            if (lottos[i] == win_nums[j]) {
                ans++;
            }
        }
    }

    int* answer = (int*)malloc(sizeof(int) * 2);

    if (answer != NULL) {
        answer[0] = rank[cnt_0 + ans];
        answer[1] = rank[ans];
    }

    return answer;
}