#include <stdio.h>
#define bool int
bool isPerfectSquare(int num) 
{
    if(num==1)
        return 1;
    if(num==0)
        return 0;
    if(num<0)
        return 0;
    int tmp=num/2;
    while(tmp>=1)
    {
        if(num%tmp == 0)
        {
            if(num/tmp == tmp)
                return 1;
        }
        tmp--;
    }
    return 0;
}
int main() 
{   
    int result;
    result = isPerfectSquare(4);
    printf("%d\n", result);
} 
