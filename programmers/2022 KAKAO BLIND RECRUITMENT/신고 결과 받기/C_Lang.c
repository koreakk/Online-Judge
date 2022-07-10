
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LEN_ID      22

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k)
{
    int i, j;

    bool** map = (bool**)malloc(sizeof(bool*) * id_list_len);
    for (i = 0; i < id_list_len; i++) {
        map[i] = (bool*)malloc(sizeof(bool) * id_list_len);
        memset(map[i], false, sizeof(bool) * id_list_len);
    }

    int* number_of_reports = (int*)malloc(sizeof(int) * id_list_len);
    memset(number_of_reports, 0, sizeof(int) * id_list_len);

    char copy[MAX_LEN_ID];      // 복사할 문자배열
    char* user_id = NULL;       // 신고한 ID
    char* reported_id = NULL;   // 신고당한 ID
    int user_id_index = 0;
    int repored_id_index = 0;

    for (i = 0; i < report_len; i++) {
        strcpy(copy, report[i]);
        user_id = strtok(copy, " ");
        reported_id = strtok(NULL, " ");

        for (j = 0; j < id_list_len; j++) {
            if (strcmp(user_id, id_list[j]) == 0)
                user_id_index = j;
            else if (strcmp(reported_id, id_list[j]) == 0)
                repored_id_index = j;
        }

        if (!map[user_id_index][repored_id_index]) {    // 중복 제거
            map[user_id_index][repored_id_index] = true;
            number_of_reports[repored_id_index] += 1;
        }

    }

    int* answer = (int*)malloc(sizeof(int) * id_list_len);
    memset(answer, 0, sizeof(int) * id_list_len);

    for (i = 0; i < id_list_len; i++) {
        for (j = 0; j < id_list_len; j++) {
            if (map[i][j] && number_of_reports[j] >= k)
                answer[i] += 1;
        }
    }

    // 메모리 해제
    for (i = 0; i < id_list_len; i++) {
        free(map[i]);
    }
    free(map);
    free(number_of_reports);


    return answer;
}