#include <stdio.h>

#define bool int
#define false 0
#define true 1
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    bool *res;
    int i;
    int sum = 0;

    res = (bool *)malloc(sizeof(bool)*ASize);

    for(i=0; i<ASize; i++){
        sum = sum*2 + A[i];
        if(sum%5)
            res[i] = 0;
        else 
            res[i] = 1;
        sum = sum%5;
    }
    *returnSize = ASize;
    return res;
}

int main()
{
    int i;
    int *res;
    int returnSize;
    int N = 59;
    int nums[] = {1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,1,1,1,1,1,1,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,1,1,1};
    res = prefixesDivBy5(nums, N, &returnSize);
    for(i=0; i<N; i++){
        printf("%d\n", res[i]);
    }
}
