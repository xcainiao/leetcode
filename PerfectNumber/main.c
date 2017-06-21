#include <stdio.h>
#define bool int

bool checkPerfectNumber(num)
{
    if(num==6 || num==28 || num==496 || num==8128 || num==33550336)
        return 1;
    return 0;
}

bool checkPerfectNumber(int num)
{
    int sum = 0;
    int tmp = num/2;
    if(num==0)
        return 0;
    if(num<0)
        return 0;
    while(tmp)
    {
        if(num%tmp==0)
            sum = sum + tmp;
        tmp = tmp - 1;
    }
    if(sum==num)
        return 1;
    else
        return 0;
}
int main() 
{   
    int result;
    result = checkPerfectNumber(100000000);
    printf("%d\n", result);
} 
