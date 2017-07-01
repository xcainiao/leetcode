#include <stdio.h>

int countSegments(char* s) 
{   
    int i;
    char* p;
    int result = 0;
    if(!s)
        return 0;
   for(i=0;i<strlen(s);i++)
    {
        if(s[i] != ' ')
            break;
        else
            s[i] = '1';
    }
    if(i == strlen(s))
        return 0;
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i] != ' ')
            break;
        else
            s[i] = '1';
    } 
    p = s;
    while(p<(s+strlen(s)))
    {
        p = strchr(p, ' ');
        if(p)
        {
            while(*(p+1) == ' ')
            {
                p = p + 1;
            }
        }
        else
        {
            break;
        }
        result = result + 1;
        p = p + 1;
    }
    return result+1;
}

int main() 
{   
    int result;
    char s[] = " 1  2 3";
    result = countSegments(s);
    printf("%d\n", result);
} 
