#include <stdio.h>

int maxProfit(int* nums, int pricesSize) {
    
    int max = 0;
    for(int i=0;i<pricesSize;i++)
    {
        for(int j=i;j<pricesSize;j++)
        {
            if(nums[j]-nums[i] > max)
            {
                max = nums[j] - nums[i];
            }
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
	int result;
	int prices[6] = {7, 1, 5, 3, 6, 4};
	result = maxProfit(prices, 6);
	printf("%d\n", result);
}
