#include <stdio.h>
#define bool int
bool isUgly(int num) 
{
    if(num==0)
        return 0;
    while(num!=1)
    {
        if(num%2==0)
        {
            num = num/2;
        }
        else if(num%3==0)
        {
            num = num/3;
        }
        else if(num%5==0)
        {
            num = num/5;
        }
        else
        {
            break;
        }
    }
    if(num == 1)
        return 1;
    else
        return 0;
}
int main() 
{   
    int result;
    result = isUgly(8);
    printf("%d\n", result);
} 
