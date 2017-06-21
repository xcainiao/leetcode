#include <stdio.h>
#define bool int
int arrangeCoins(int n) 
{
   int i = 1;
   long sum = 0;
   int result = 0;
   while(sum<=n)
   {
        sum = sum+i;
        i++;
        result++;
   }
   return result-1;
}
int main() 
{   
    int result;
    result = arrangeCoins(2147483647);
    printf("%d\n", result);
} 
