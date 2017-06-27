#include <stdio.h>
int climbStairs(int n) 
{
    int tmp[n+2];
    int i;

    tmp[0] = 1;
    tmp[1] = 2;
    for(i=2;i<n;i++)
    {
       tmp[i] = tmp[i-2]+tmp[i-1];
    }
    return tmp[n-1];
}
int main() 
{   
    int result;
    result = climbStairs(8);
    printf("%d\n", result);
} 
