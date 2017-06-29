#include <stdio.h>
#define bool int
bool isPowerOfFour(int n)  
{
    if(n==0)
        return 0;
    while(n%4 == 0)
    {   
        n = n/4;
    }   
    if(n==1)
        return 1;
    return 0;
}
int main() 
{   
    int result;
    result = isPowerOfFour(16);
    printf("%d\n", result);
} 
