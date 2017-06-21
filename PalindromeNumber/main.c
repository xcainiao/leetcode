#include <stdio.h>
#define bool int
bool isPalindrome(int num) 
{
    int temp;
    int sum=0;
    if(num<0)
        return 0;
    temp=num;
    while(num)
    {
        sum = sum*10 + num%10; 
        num /= 10;
    }
    if(temp == sum) 
        return 1;
	else
        return 0;
}
int main() 
{   
    int result;
    result = isPalindrome(18);
    printf("%d\n", result);
} 
