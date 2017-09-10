#include <stdio.h>

int max(dp1, dp2)
{
    return dp1>dp2?dp1:dp2;
}

int lengthOfLIS(int* nums, int numsSize) 
{
    int i, j;
    int maxnum = 0;
    int result = 1; 
    int dp[50000];
    int dpnums[50000];
    if(numsSize == 0)
        return 0; 
    for(i=0; i<numsSize; i++)
    {
        dp[i] = 1;
        dpnums[i] = 1;
    }
    for(i=0; i<numsSize; i++)
    {
        for(j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
            {
                if((dp[j]+1) == dp[i])
                    dpnums[i] = dpnums[i] + dpnums[j];
                if((dp[j]+i) > dp[i])
                {
                    dp[i] = dp[j] +1;
                    dpnums[i] = dpnums[j];
                }
            }
        }
    }
    for(i=0;i<numsSize;i++)
    {
        printf("%d\n", dpnums[i]);
    }
    return maxnum;
}

int main(int argc, char *argv[])
{
    int nums[8] = {10, 9, 2, 5, 3, 7, 101, 18};
    int numsSize = 8;
	int result;
	result = lengthOfLIS(nums, numsSize); 
	//printf("%d\n", result);
}
