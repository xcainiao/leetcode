#include <stdio.h>

typedef struct {
    int stack[10000];
    int head;
} MinStack;

MinStack* minStackCreate(int maxSize) {
   MinStack *stack;
   stack = (MinStack*)malloc(sizeof(MinStack));
   stack->head = -1;
   return stack;
}

void minStackPush(MinStack* obj, int x) {
    (obj->head)++;
    obj->stack[obj->head] = x;
}

void minStackPop(MinStack* obj) {
    if(obj->head!=-1)
        (obj->head)--;
}

int minStackTop(MinStack* obj) 
{
    //printf("%d\n", obj->head);
    return obj->stack[obj->head];
}

int minStackGetMin(MinStack* obj) {
   int i;
   int j;
   int min=2147483647;
   if(obj->head==-1)
        return;
   for(i=0;i<=obj->head;i++)
   {
        if(obj->stack[i]<=min)
            min = obj->stack[i];
   }
   /*
   (obj->head)--;
   for(j=i;j<(obj->head);j++)
   {
       obj->stack[j] = obj->stack[j+1];
   }
   */
   return min;
}

void minStackFree(MinStack* obj) {
   free(obj); 
}
int main() 
{   
    int tmp;
    struct MinStack* obj = minStackCreate(1);
    minStackPush(obj, 2147483646);
    minStackPush(obj, 2147483646);
    minStackPush(obj, 2147483647);
    tmp = minStackTop(obj);
    printf("%d\n", tmp);
    minStackPop(obj);
    tmp = minStackGetMin(obj);
    printf("%d\n", tmp);
    minStackPop(obj);
    tmp = minStackGetMin(obj);
    printf("%d\n", tmp);
    printf("-------------\n");
    minStackPop(obj);
    minStackPush(obj, 2147483647);
    tmp = minStackTop(obj);
    printf("%d\n", tmp);
    tmp = minStackGetMin(obj);
    printf("%d\n", tmp);
    
    /*
    tmp = minStackGetMin(obj);
    tmp = minStackGetMin(obj);
    tmp = minStackTop(obj); 
    */
} 
