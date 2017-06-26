#include <stdio.h>
#define bool int
bool isPowerOfThree(int n) 
{
    if(n==0)
        return 0;
    while(n%3 == 0)
    {
        n = n/3;
    }
    if(n==1)
        return 1;
    return 0;
}
int main() 
{   
    int result;
    result = isPowerOfThree(9);
    printf("%d\n", result);
} 
