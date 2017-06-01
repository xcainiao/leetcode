#include <stdio.h>
#include<string.h>
char* reverseWords(char* s) 
{
    int length;
    int tmplength;
    int beginlength = 0;
    int i;
    char *result;
    char* p;
    char* delim=" ";
    length = strlen(s); 
    result = (char*)malloc(sizeof(char)*length);
    p=strtok(s,delim);
    while(p!=NULL)
    {
        tmplength = strlen(p);
        for(i=0;i<tmplength;i++)
        {
            result[i+beginlength] = p[tmplength-i-1];
        }
        result[tmplength+beginlength] = ' ';
        beginlength = tmplength + 1 + beginlength;
        p=strtok(NULL,delim);
    }
    result[length] = NULL;
    return result;
}

int main(int argc, char *argv[])
{
    char *result;
	char s[] = "abc de fg";
    result = reverseWords(s);
    printf("%s\n", result);
}

