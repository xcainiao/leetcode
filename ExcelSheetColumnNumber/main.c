#include <stdio.h>

int titleToNumber(char* s)
{
    int i;
    int sum=0;
    for(i=0;i<s[i]!='\0';i++)
    {   
        sum = (sum + (s[i]-'A'+1))*26;
    }   
    return sum/26;
}

int main(int argc, char *argv[])
{
	int result;
	char s[] = "AA";
	result = titleToNumber(s);
	printf("%d\n", result);
}
