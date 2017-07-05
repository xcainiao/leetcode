#include <stdio.h>
#define bool int
bool isValid(char *s) 
{
   int a_l = 0;
   int a_r = 0;
   
   int b_l = 0;
   int b_r = 0;
   
   int c_l = 0;
   int c_r = 0;

   int i;
   for(i=0;i<strlen(s);i++)
   {
        if(s[i]=='(')
            a_l = 1;

   }

}
int main() 
{   
    int result;
    char s[] = "(12)";
    result = isValid(s);
    printf("%d\n", result);
} 
