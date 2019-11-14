#include <stdio.h>

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int i, j=0, k=0;
    int *res;
    int tmp1[ASize];
    int tmp2[ASize];
    res = malloc(sizeof(int)*ASize);

    for(i=0; i<ASize; i++){
        tmp1[i] = -1;
        tmp2[i] = -1;
    }
    for(i=0; i<ASize; i++){
        if(A[i]%2==0){
            tmp1[j] = A[i];
            j++;
        }
        else {
            tmp2[k] = A[i];
            k++;
        }
    }
    i = 0;
    for(j; j>0; j--){
        res[i] = tmp1[j-1];
        i++;
    }
    for(k; k>0; k--){
        res[i] = tmp2[k-1];
        i++;
    }
    *returnSize = ASize;
    return res;
}

int main(int argc, char *argv[])
{
    int i;
    int A[] = {3, 1, 2, 4};
    int ASize = 4;
    int resSize;
    int *res;
    res = sortArrayByParity(A, ASize, &resSize);
    for(i=0; i<resSize; i++){
        printf("%d\n", res[i]);
    }
}
