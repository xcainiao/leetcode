#include <stdio.h>
int strStr(char* haystack, char* needle) 
{
    int i;
    int j;
    for(i=0;i<strlen(haystack);i++)
    {
        if(haystack[i] == *needle)
        {
            for(j=0;j<strlen(needle);j++)
            {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == strlen(needle))
                return i;
        }
    }
    return -1;
}

int main() 
{   
    int result;
	char s[] = "aaa";
	char s1[] = "a";
    result = strStr(s, s1);
    printf("%d\n", result);
} 
