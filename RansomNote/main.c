#include <stdio.h>

#define  bool int

bool canConstruct(char* ransomNote, char* magazine) 
{
    int len1;
    int len2;
    int i;
    int j;
    int res=0;
    len1 = strlen(ransomNote);
    len2 = strlen(magazine);
    if(len1==0)
        return 1;
    for(i=0;i<len1;i++)
    {   
        for(j=0;j<len2;j++)
        {
            if(!(magazine[j]^ransomNote[i]))
            {
                res++;
                magazine[j] = '0';
                break;
            }
        }
    }   
    if(res == len1)
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
	int result;
	char ransomNote[] = "aa";
	char magazine[] = "ab";
	
    result = canConstruct(ransomNote, magazine);
	printf("%d\n", result);
}
