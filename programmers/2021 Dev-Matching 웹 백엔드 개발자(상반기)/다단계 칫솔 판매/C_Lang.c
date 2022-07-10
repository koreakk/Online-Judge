#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// enroll_len은 배열 enroll의 길이입니다.
// referral_len은 배열 referral의 길이입니다.
// seller_len은 배열 seller의 길이입니다.
// amount_len은 배열 amount의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* enroll[], size_t enroll_len, const char* referral[], size_t referral_len, const char* seller[], size_t seller_len, int amount[], size_t amount_len) {
    
    int* seller_idx = (int*)malloc(sizeof(int) * seller_len);

    for (int i = 0; i < seller_len; i++) {
        for (int j = 0; j < enroll_len; j++) {
            if (strcmp(seller[i], enroll[j]) == 0)
                seller_idx[i] = j;
        }
    }

    int* _referral = (int*)malloc(sizeof(int) * referral_len);

    for (int i = 0; i < referral_len; i++) {
        _referral[i] = -1;

        for (int j = 0; j < enroll_len; j++) {
            if (strcmp(referral[i], enroll[j]) == 0)
                _referral[i] = j;
        }
    }


    int* answer = (int*)malloc(sizeof(int) * enroll_len);
    memset(answer, 0, sizeof(int) * enroll_len);

    for (int i = 0; i < seller_len; i++) {
        int idx = seller_idx[i];
        int curr_seller = amount[i] * 100;

        while (idx != -1 && curr_seller > 0) {
            answer[idx] += curr_seller - (curr_seller / 10);
            curr_seller /= 10;
            idx = _referral[idx];
        }
    }

    free(seller_idx);
    free(_referral);

    return answer;
}