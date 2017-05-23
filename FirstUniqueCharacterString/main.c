#include <stdio.h>

int firstUniqChar(char* s) {
    int i,j;
    if(s[1] == '\0')
        return 0;
    for(i=0;s[i]!='\0';i++)
    {
        for(j=0;s[j]!='\0';j++)
        {
            if(s[i]==s[j]&&i!=j)
                break;
            if(s[j+1]=='\0')
                return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
	int result;
	char s[] = "leetcode";
	result = firstUniqChar(s); 
	printf("%d\n", result);
}
