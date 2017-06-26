#include <stdio.h>
#define bool int
bool isPowerOfTwo(int n) 
{
    if(n==0)
        return 0;
    while(n%2 == 0)
    {
        n = n/2;
    }
    if(n==1)
        return 1;
    return 0;
}
int main() 
{   
    int result;
    result = isPowerOfTwo(9);
    printf("%d\n", result);
} 
