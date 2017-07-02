#include <stdio.h>

char* reverseString(char* s) {
    char *res = (char*)malloc(sizeof(char)*strlen(s)+1);
    int length = strlen(s);
    int i;
    printf("%d\n", strlen(s));
    for(i=0;i<length;i++)
    {
    res[i] = s[length-1-i];
    }
    res[length] = '\0';
    //printf("%s\n", res);
    return res;
}
int main() 
{   
    char* result;
    char s[] = "......a.....";
    result = reverseString(s);
    printf("%s\n", result);
} 
