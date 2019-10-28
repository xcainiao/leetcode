#include <stdio.h>

int* diStringMatch(char * S, int* returnSize){
    int *res;
    *returnSize = strlen(S)+1;
    res = malloc(sizeof(int)* *returnSize);
    int I = 0;
    int D = *returnSize-1;
    int i;
    for(i=0; i<*returnSize-1; i++){
        if(S[i] == 'I'){
            res[i] = I;
            I++;
        }
        else{
            res[i] = D;
            D--;
        }
    }
    res[i] = D;
    return res;
}

int main(int argc, char *argv[])
{
    int i;
    char *S = "IDID";
    int *res;
    int returnSize = 0;
    res = diStringMatch(S, &returnSize);
    for(i=0; i<returnSize; i++){
        printf("%d\n", res[i]);
    }
}
