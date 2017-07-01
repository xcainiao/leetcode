#include <stdio.h>

#define bool int

typedef struct {
    int queue[10000];
    int head;
    int length;
} MyQueue;

MyQueue* myQueueCreate(int maxSize) 
{
    MyQueue* queue;
    queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->head = 0;
    queue->length = 0;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
   obj->queue[obj->length] = x; 
   obj->length++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int result;
    result = obj->queue[obj->head]; 
    obj->head++;
    return result;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int result;
    result = obj->queue[obj->head]; 
    return result;
    
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->length <= obj->head)
        return 1;
    return 0;
}

void myQueueFree(MyQueue* obj) {
    
}
void main()
{
    
}
