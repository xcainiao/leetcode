#include <stdio.h>
#define bool int
bool checkPerfectNumber(int num) 
{
    int sum = 0;
    int tmp = num-1; 
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
    result = checkPerfectNumber(28);
    printf("%d\n", result);
} 
