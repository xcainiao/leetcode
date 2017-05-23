#include <stdio.h>

char findTheDifference(char* s, char* t) 
{
    int length = strlen(s);
    int i;
    long res = 0;
    for(i=0;i<length;i++)
    {   
        res += t[i] - s[i];
    }   
    res = res + t[length];
    return res;
}

int main(int argc, char *argv[])
{
	char s[] = "abcd";
	char t[] = "abcde";
	char result;
	result = findTheDifference(s, t);
	printf("%c\n", result);
}
