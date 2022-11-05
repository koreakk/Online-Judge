#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// info_len은 배열 info의 길이입니다.
// edges_rows는 2차원 배열 edges의 행 길이, edges_cols는 2차원 배열 edges의 열 길이입니다.
int solution(int info[], size_t info_len, int **edges, size_t edges_rows, size_t edges_cols) {

    bool graph[17][17] = {0, };

    for (int i = 0; i < edges_rows; i++) {
        graph[edges[i][0]][edges[i][1]] = true;
    }
    
    // DFS
    bool* visited = (bool*)malloc(sizeof(bool) * (1ULL << info_len));
    memset(visited, false, sizeof(bool) * (1ULL << info_len));

    int stack[1000] = {0, };
    int top = 0;
    int answer = 0;

    stack[top++] = 1; // 0000 0000 0000 0001
    
    while (top != 0) {

        int pop = stack[--top];
        if (visited[pop])
            continue;

        visited[pop] = true;

        int total = 0;
        int wolf = 0;

        for (int i = 0; i < info_len; i++) {
            if (pop & (1 << i)) {
                total++;
                wolf += info[i];
            }
        }
        
        int sheep = total - wolf;
        if (sheep <= wolf)
            continue;

        answer = (answer > sheep) ? answer : sheep;

        for (int i = 0; i < info_len; i++) {
            if (!(pop & (1 << i)))
                continue;

            for (int j = 0; j < info_len; j++) {
                if (graph[i][j])
                    stack[top++] = pop | (1 << j);
            }
        }
    }

    free(visited);
    return answer;
}