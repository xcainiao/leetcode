#include <stdio.h>

#define bool int

bool isAnagram(char* s, char* t) 
{
    int i;
    int n1 = 0;
    int n2 = 0;
    int tmp[26]={0};
    for(i=0;s[i]!=NULL;i++);
    n1 = i;
    for(i=0;t[i]!=NULL;i++);
    n2 = i;
    if(n1 != n2)
        return 0;
    for(i=0;i<n1;i++)
    {
        tmp[s[i]-'a']++;
        tmp[t[i]-'a']--;
    }
    for(i=0;i<26;i++)
    {
        if(tmp[i]<0) 
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
	int result;
	char s[] = "leetcode";
    char t[] = "edocteel";
	result = isAnagram(s, t); 
	printf("%d\n", result);
}
