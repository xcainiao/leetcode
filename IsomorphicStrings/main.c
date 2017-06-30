#include <stdio.h>
/*
 *
 *time limit exceeded
 *
 */
#define bool int

bool isIsomorphic(char* s, char* t) 
{
    int i;
    int j;
    int tmp[500];
    int tmp2[500];
    for(i=0;i<500;i++)
    {
        tmp[i] = 500;
    }
    for(i=0;i<500;i++)
    {
        tmp2[i] = 500;
    }
    for(i=0;i<strlen(s);i++)
    {
       if(tmp[s[i]] == 500)
       {
            tmp[s[i]] = s[i] - t[i]; 
       }
       else
       {
            if(tmp[s[i]] != s[i]-t[i])
                return 0;
       }
       if(tmp2[t[i]] == 500)
       {
            tmp2[t[i]] = t[i] - s[i]; 
       }
       else
       {
            if(tmp2[t[i]] != t[i]-s[i])
                return 0;
       }
    }
    return 1;
    /*
    for(i=0;i<500;i++)
    {
        tmp[i] = 500;
    }
    for(i=0;i<strlen(t);i++)
    {
       if(tmp[t[i]] == 500)
       {
            tmp[t[i]] = t[i] - s[i]; 
       }
       else
       {
            if(tmp[t[i]] != t[i]-s[i])
                return 0;
       }
    }
    */
    /*
    if(strcmp(s, t)==0)
        return 1;
    return 0;
    */

}

int main() 
{   
    int result;
    char s[] = "1da";
    char t[] = "1da";
    result = isIsomorphic(s, t);
    printf("%d\n", result);
} 
