#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID              10000
#define RECORD_MAX_LEN      15
#define END_TIME            ((23 * 60) + 59)

int formula(int time, int fees[]) {
    if (time <= fees[0]) return fees[1];
    int q = (time - fees[0] + fees[2] - 1) / fees[2];
    return fees[1] + q * fees[3];
}

int intTime(const char* time) {
#define INT(s) ((s) - '0')
    int h = INT(time[0]) * 10 + INT(time[1]);
    int m = INT(time[3]) * 10 + INT(time[4]);
    return h * 60 + m;
}

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    const int size = sizeof(int) * MAX_ID;

    int* times = (int*)malloc(size);              // 누적 시간
    int* inTimes = (int*)malloc(size);            // 시작 시간

    for (int i = 0; i < MAX_ID; i++) {
        times[i] = 0;
        inTimes[i] = -1;
    }

    char copy[RECORD_MAX_LEN];
    int time = 0;
    int id = 0;
    char* state = NULL;

    for (int i = 0; i < records_len; i++) {
        strcpy(copy, records[i]);
        // 시각, 차량번호, 내역 분할
        time = intTime(strtok(copy, " "));
        id = atoi(strtok(NULL, " "));
        state = strtok(NULL, " ");

        if (!strcmp(state, "IN"))
            inTimes[id] = time;

        else {  // OUT
            times[id] += time - inTimes[id];
            inTimes[id] = -1;
        }
    }

    // 주차 차량 개수 + 출차기록 없는 차량 처리
    int count = 0;
    for (int i = 0; i < MAX_ID; i++) {
        if (times[i] != 0 || inTimes[i] != -1) {
            if (inTimes[i] != -1)
                times[i] += END_TIME - inTimes[i];

            count++;
        }
    }

    int answer_index = 0;
    int* answer = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < MAX_ID; i++) {
        if (times[i] != 0)
            answer[answer_index++] = formula(times[i], fees);
    }

    free(times);
    free(inTimes);

    return answer;
}