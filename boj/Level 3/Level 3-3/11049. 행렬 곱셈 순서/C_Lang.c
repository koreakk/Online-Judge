#include <stdio.h>
#define INF 0x7FFFFFFF

int info[500][2], dp[500][500];

int min(int l, int r) { return l < r ? l : r; }
    
int f(int lo, int hi) {
    if (dp[lo][hi] || lo == hi)
        return dp[lo][hi];
    
    dp[lo][hi] = INF;
    for (int mid = lo; mid < hi; ++mid) {
        dp[lo][hi] = min(
            dp[lo][hi],
            f(lo, mid) + f(mid + 1, hi) +
                info[lo][0] * info[hi][1] * info[mid][1]
        );
    }

    return dp[lo][hi];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);

        info[i][0] = n;
        info[i][1] = m;
    }

    printf("%d\n", f(0, n - 1));
}