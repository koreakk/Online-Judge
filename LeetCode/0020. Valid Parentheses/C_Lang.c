#include <string.h>
#include <stdbool.h>

bool isValid(char * s) {
    size_t length = strlen(s);

    char *stack = (char*)malloc(sizeof(char) * length);
    int top = 0;

    for (int i = 0; i < length; i++) {
        switch (s[i])
        {
        case '(':
            stack[top++] = ')';
            break;
        case '[':
            stack[top++] = ']';
            break;
        case '{':
            stack[top++] = '}';
            break;
        default:
            if (top == 0 || stack[--top] != s[i])
                return false;                
            break;
        }
    }

    return top == 0;
}