#include <stdio.h>
int findLUSlength(char* a, char* b) 
{
    if(!strcmp(a, b))
        return -1;
    return strlen(a)>strlen(b)?strlen(a):strlen(b);
}
int main() 
{     
   int result;
   char a[] = "123";
   char b[] = "1234";
   result = findLUSlength(a, b); 
   printf("%d\n", result);
} 
