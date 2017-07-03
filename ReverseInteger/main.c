#include <stdio.h>

int reverse(int x)  
{
   long result = 0;
   while(x/10)
   {   
        result = result*10 + x%10;
        x = x/10;
   }   
   result = result*10 + x%10;
   if(result>INT_MAX)
       return 0;
    if(result<INT_MIN)
        return 0;
   return result;
}

int main() 
{   
    int result;
    result = reverse(15);
    printf("%ld\n", result);
} 
