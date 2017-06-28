#include <stdio.h>

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
    int x,y,z,t;
    int result = 0;
    for(x=0;x<ASize;x++)
    {
        for(y=0;y<BSize;y++)
        {
            for(z=0;z<CSize;z++)
            {
                for(t=0;t<DSize;t++)
                {
                    if(!(A[x]+B[y]+C[z]+D[t]))
                        result++;
                }
            }
        }   
    }
    return result;
}

int main() 
{   
    int result;
    int a[2] = {1, 2};
    int b[2] = {-2, -1};
    int c[2] = {-1, 2};
    int d[2] = {0, 2};
    result = fourSumCount(a, 2, b, 2, c, 2, d, 2);
    printf("%d\n", result);
} 
