#include <stdio.h>
#define bool int
bool checkRecord(char* s) 
{
   int alen = 0; 
   int length = strlen(s);
   int i;
   for(i=0;i<length;i++)
   {
       //printf("%c\n", s[i]); 
       if(i<length-2&&s[i] == 'L'&&s[i+1]=='L'&&s[i+2]=='L')
       {
           return 0;
       }
       if(s[i] == 'A')
            alen++;
       if(alen==2)
            return 0;
   }
   return 1;
}
int main() 
{   
    int result;
    char a[] = "LALL";
    result = checkRecord(a);
    printf("%d\n", result);
} 
