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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    *returnSize = 0;
    int* answer = NULL;

    HashTable ht;
    InitHashTable(&ht, numsSize);

    PHashNode Node = NULL;
    for (int i = 0; i < numsSize; i++) {
        Node = ht.GetNode(&ht, target - nums[i]);

        if (Node != NULL) {
            *returnSize = 2;
            answer = (int*)malloc(sizeof(int) * 2);

            answer[0] = i;
            answer[1] = Node->val;

            break;
        }

        ht.InsertNode(&ht, nums[i], i);
    }

    ht.Release(&ht);
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