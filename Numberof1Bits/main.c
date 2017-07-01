#include <stdio.h>
int hammingWeight(int n) {
    int result = 0;
    int tmp;
    while(n)
    {
        tmp = (n)&1;
        if(tmp)
            result++;
        n = n>>1;
    }
    return result;
}
int main() 
{   
    int result;
    result = hammingWeight(11);
    printf("%d\n", result);
} 
