#include <stdio.h>
#define uint32_t int
uint32_t reverseBits(uint32_t n) 
{
    int i;
    long result = 0;
    int bit;
    for(i=0;i<32;i++)
    {
        bit = n&1;
        result = result<<1;
        //printf("%d\n", bit);
        result = result | bit;
        n = n>>1;
    }
    //printf("%d\n", result);
    //printf("%d\n", result);
    /* 
    for(i=0;i<32;i++)
    {
        bit = result&1;
        printf("%d\n", bit);
        result = result>>1;
    }
    */
    return result;
}

int main() 
{   
    int result;
    result = reverseBits(1);
    printf("%ld\n", result);
} 
