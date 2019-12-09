#include <stdio.h>

void duplicateZeros(int* arr, int arrSize){
    int *res;
    int i, j;
    res = (int*)malloc(sizeof(int)*arrSize);
    for(i=0; i<arrSize; i++){
        res[i] = arr[i];
    }
    for(j=0, i=0; j<arrSize; j++){
        arr[j] = res[i];
        if(arr[j]==0 && j<(arrSize-1)){
            j++;
            arr[j] = 0;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int i;
    int tmp[] = {1,0,2,3,0,4,5,0};
    duplicateZeros(tmp, 8);
    for(i=0; i<8; i++){
        printf("%d\n", tmp[i]);
    }
    
}
