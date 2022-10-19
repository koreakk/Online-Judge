#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _HashNode
{
    int key;
    int val;
    struct _HashNode* Next;
} HashNode, * PHashNode;

typedef struct _HashTable
{
    PHashNode* Map;
    size_t Size;
    int (*HashKey)(struct _HashTable*, int);
    void (*InsertNode)(struct _HashTable*, int, int);
    PHashNode(*GetNode)(struct _HashTable*, int);
    void (*Release)(struct _HashTable*);
} HashTable, * PHashTable;

int HashKey(PHashTable ht, int _key);
void InsertNode(PHashTable ht, int _key, int _val);
PHashNode GetNode(PHashTable ht, int _key);
void Release(PHashTable ht);

void InitHashTable(PHashTable ht, size_t _HashSize) {
    ht->HashKey    = HashKey;
    ht->InsertNode = InsertNode;
    ht->GetNode    = GetNode;
    ht->Release    = Release;
    ht->Size       = _HashSize;
    ht->Map        = (PHashNode*)malloc(sizeof(PHashNode) * _HashSize);
    memset(ht->Map, 0, sizeof(PHashNode) * _HashSize);
}

int BinarySearch(int* nums, int numsSize, int target) {

    int l = 0, r = numsSize - 1;
    int mid = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);

        if (nums[mid] == target && (mid <= 0 || nums[mid - 1] < target))
            break;

        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    if (nums[mid] != target)
        return 0;

    int Left = mid;

    l = 0, r = numsSize - 1;
    while (l <= r) {
        mid = l + ((r - l) >> 1);

        if (nums[mid] == target && (mid >= numsSize - 1 || nums[mid + 1] > target))
            break;

        if (nums[mid] <= target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return mid - Left + 1;
}

int Compare(const void* n1, const void* n2) {
    return *(int*)n1 - *(int*)n2;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int* A = nums1, * B = nums2;
    int ALen = nums1Size;
    int BLen = nums2Size;

    if (ALen < BLen) {
        // SWAP
        A = nums2, B = nums1;
        ALen = nums2Size;
        BLen = nums1Size;
    }

    qsort(B, BLen, sizeof(int), Compare);

    HashTable ht;
    InitHashTable(&ht, 1000);

    for (int i = 0; i < ALen; i++) {
        PHashNode Node = ht.GetNode(&ht, A[i]);

        if (Node == NULL)
            ht.InsertNode(&ht, A[i], 1);
        else
            Node->val++;
    }

    int* answer = (int*)malloc(sizeof(int) * BLen);
    int top = 0;

    for (int i = 0; i < ALen; i++) {
        PHashNode Node = ht.GetNode(&ht, A[i]);

        if (Node == NULL)
            continue;

        int Counter = BinarySearch(B, BLen, A[i]);
        if (Counter > Node->val)
            Counter = Node->val;

        for (int j = 0; j < Counter; j++)
            answer[top++] = A[i];

        Node->val = 0;
    }

    if (top == 0) {
        *returnSize = 0;
        free(answer);
        
        return NULL;
    }

    *returnSize = top;
    return answer;
}

int HashKey(PHashTable ht, int _key) {
    return _key % ht->Size;
}

void InsertNode(PHashTable ht, int _key, int _val) {
    if (ht->Map == NULL)
        return;

    int idx = ht->HashKey(ht, _key);

    PHashNode NewNode = (PHashNode)malloc(sizeof(HashNode));
    NewNode->key = _key;
    NewNode->val = _val;

    NewNode->Next = ht->Map[idx];
    ht->Map[idx] = NewNode;
}

PHashNode GetNode(PHashTable ht, int _key) {
    if (ht->Map == NULL)
        return NULL;

    PHashNode Node = ht->Map[ht->HashKey(ht, _key)];

    while (Node != NULL && Node->key != _key)
        Node = Node->Next;

    return Node;
}

void Release(PHashTable ht) {
    if (ht->Map == NULL)
        return;

    PHashNode Node = NULL;
    PHashNode Prev = NULL;

    for (int i = 0; i < ht->Size; i++) {
        Node = ht->Map[i];

        while (Node != NULL) {
            Prev = Node;
            Node = Node->Next;

            free(Prev);
        }
    }

    free(ht->Map);
    ht->Map = NULL;
}
