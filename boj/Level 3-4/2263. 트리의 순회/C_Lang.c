#include <stdio.h>
#include <stdlib.h>

int findIndex(const int* array, int size, int val)
{
    for (int i = 0; i < size; ++i) {
        if (array[i] == val) {
            return i;
        }
    }

    return -1;
}

void solution(int* result, const int* inorder, const int* postorder, int size)
{
    if (size > 0) {
        const int root  = postorder[size - 1];
        const int lSize = findIndex(inorder, size, root);
        const int rSize = size - lSize - 1;

        *result = root;

        solution(result + 1, inorder, postorder, lSize);
        solution(result + lSize + 1, inorder + lSize + 1, postorder + lSize, rSize);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    const size_t memSize = sizeof(int) * n;
    int* inorder   = (int*)malloc(memSize);
    int* postorder = (int*)malloc(memSize);

    for (int i = 0; i < n; ++i) {
        scanf("%d", inorder + i);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", postorder + i);
    }

    int* result = (int*)malloc(memSize);
    solution(result, inorder, postorder, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i]);
    }
    putchar('\n');

    free(inorder);
    free(postorder);
    free(result);

    return 0;
}