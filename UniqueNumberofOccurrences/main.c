#include <stdio.h>

int uniqueOccurrences(int* arr, int arrSize){
    int tmp[2001];
    int i, j;
    for(i=0; i<2001; i++){
        tmp[i]=0;
    }
    for(i=0; i<arrSize; i++){
       tmp[arr[i]+1000]++;
    }
    for(i=0; i<2001; i++){
        if(tmp[i] == 0)
            continue;
        for(j=0; j<2001 && j!=i; j++){
            if(tmp[i] == tmp[j]){
                return 0;
            }
        }
    }
    return 1;
}



int main(int argc, char *argv[])
{
    int arr[8] = {1,1,2,2,1,1,3,3};
    printf("%d\n", uniqueOccurrences(arr, sizeof(arr)/sizeof(int)));
    return 0;
}
