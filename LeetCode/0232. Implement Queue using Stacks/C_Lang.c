#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int input[100];
    int output[100];
    int Itop;
    int Otop;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->Itop = obj->Otop = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->input[++(obj->Itop)] = x;
}

int myQueuePeek(MyQueue* obj) {
    if (obj->Otop == -1) {
        while (obj->Itop != -1)
            obj->output[++(obj->Otop)] = obj->input[(obj->Itop)--];
    }

    return obj->output[obj->Otop];
}

int myQueuePop(MyQueue* obj) {
    myQueuePeek(obj);
    return obj->output[(obj->Otop)--];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->Itop == -1 && obj->Otop == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/