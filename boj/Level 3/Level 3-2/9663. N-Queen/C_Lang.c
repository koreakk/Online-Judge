#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[15][15];

bool check(int n, int x, int y)
{
    for (int i = 0; i < y; ++i) {
        if (board[i][x]) {            
            return false;
        }
    }
    
    for (int i = y, j = x; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }
    
    for (int i = y, j = x; i >= 0 && j < n; --i, ++j) {
        if (board[i][j]) {
            return false;
        }
    }
    
    return true;
}

int dfs(int n, int y)
{
    if (y >= n) {
        return 1;
    }
    
    int result = 0;
    
    for (int x = 0; x < n; ++x) {
        if (check(n, x, y)) {
            board[y][x] = 1;
            result += dfs(n, y + 1);
            board[y][x] = 0;
        }
    }
    
    return result;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    printf("%d\n", dfs(n, 0));
    return 0;
}
