#include <stdio.h>
#define bool int

bool judgeSquareSum(int c) 
{
    int tmp = sqrt(c);
    int i;
    int j;
    for(i=0;i<=tmp;i++)
    {
        for(j=0;j<=tmp;j++)
        {
            if(i*i + j*j == c)
                return 1;
        }
    }
    return 0;
}

int main() 
{   
    int result;
    result = judgeSquareSum(3);
    printf("%d\n", result);
} 
