#include <stdlib.h>

#define MIN(A, B)   ((A) < (B)) ? (A) : (B)
#define MAX(A, B)   ((A) > (B)) ? (A) : (B)

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < pricesSize; i++) {
        minPrice = MIN(minPrice, prices[i]);
        profit = MAX(profit, prices[i] - minPrice);
    }

    return profit;
}