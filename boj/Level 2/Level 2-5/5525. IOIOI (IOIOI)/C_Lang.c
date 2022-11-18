#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solution(int n, int length, const char* S)
{
    const char p[] = { "IOI" };

    int answer = 0;
    int idx = 0;
    while (idx < length)
    {
        int count = 0;
        while (idx < length && !strncmp(S + idx, p, 3)) {
            count++;
            idx += 2;
        }

        answer += count >= n ? count + 1 - n : 0;
        idx++;
    }

    return answer;
}

int main()
{
    int n, length;

    scanf("%d", &n);
    scanf("%d", &length);

    char* S = (char*)malloc(sizeof(char) * length + 1);
    scanf("%s", S);

    printf("%d\n", solution(n, length, S));
    free(S);

    return 0;
}