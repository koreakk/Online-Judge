#include <stdio.h>


void add(int* x_ptr, int* x_len, int* y_ptr, int* y_len) {
	int len = (*x_len > *y_len) ? *x_len : *y_len;
	int sum = 0;
	int carry = 0;

	for (int i = 0; i < len; i++) {
		sum = x_ptr[i] + y_ptr[i] + carry;

		x_ptr[i] = sum % 10;
		carry = sum / 10;
	}
	if (carry)
		x_ptr[len++] = carry;

	*x_len = len;
}

void print(int* ptr, int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", ptr[i]);
    }
    putchar('\n');
}

void solution(int n) {
    int x[1000] = { 0, };
    int y[1000] = { 1, };

    int* x_ptr = x;
    int* y_ptr = y;
    int* temp = NULL;
    
    int x_len = 0;
    int y_len = 1;

    for (int i = 0; i < n; i++) {
        add(x_ptr, &x_len, y_ptr, &y_len);
        // SWAP
        temp = x_ptr;
        x_ptr = y_ptr;
        y_ptr = temp;
        
        x_len ^= y_len;
        y_len ^= x_len;
        x_len ^= y_len;
    }

    print(x_ptr, x_len);
}

int main(void) {
    int n = 0;
    scanf("%d", &n);

    solution(n);
    return 0;
}