#include <stdio.h>

int solution(char* str)
{
    int result = 0;
    int minus = 1;
    int temp = 0;
    int i = 0;

    while (str[i] != '\0') {
        if ('0' <= str[i] && str[i] <= '9') {
            temp = temp * 10 + str[i] - '0';
        }
        else {
            result += temp * minus;
            temp = 0;
            if (str[i] == '-')
                minus = -1;
        }
        i++;
    }
    result += temp * minus;
    return result;
}

int main(void)
{
    char str[51];
    scanf("%s", str);
    printf("%d", solution(str));
    return 0;
}