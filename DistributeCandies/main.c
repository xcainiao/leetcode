#include <stdio.h>

int distributeCandies(int* candies, int candiesSize) 
{
    int num[200001];
    long i;
    int count = 0;
    for(i=0;i<200001;i++)
    {
        num[i] = 0;
    }
    for(i=0;i<candiesSize;i++)
    {
        num[candies[i]+100000] = 1;
    }
    for(i=0;i<200001;i++)
    {
        if(num[i] == 1)
        {
            count++;
        }
    }
    if(count>=(candiesSize/2))
        return candiesSize/2;
    else
        return count;
}

int main(int argc, char *argv[])
{
    int result;
    int candies[6] = {1, 1, 2, 2, 3, 3};
    result = distributeCandies(candies, 6);
    printf("%d\n", result);
}

