#include <stdio.h>

#define bool int

bool detectCapitalUse(char* word)
{
    int i;
    int length;
    int count1 = 0;
    int count2 = 0;
    length = strlen(word);
    if(word[0]>=65 && word[0]<=90)
    {
        for(i=1;i<length;i++)
        {
            if(word[i]>=65 && word[i]<=90)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        if(count1!=length-1 && count2!=length-1)
        {
            return 0;
        }
    }
    else
    {
        for(i=1;i<length;i++)
        {
            if(word[i]>=65 && word[i]<=90)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char *word = "usa";     
    int result;
    result = detectCapitalUse(word);
    printf("%d\n", result);
}
