#include <stdio.h>
int findLengthOfLCIS(int* nums, int numsSize) {
    int tmp = 1;
    int max = 0;
    int i;
    if(numsSize == 1)
        return 1;
    for(i=0; i<numsSize-1; i++)
    {
        if((nums[i+1]-nums[i]) > 0)
        {
            tmp = tmp + 1;
        }
        else {
            tmp = 1;
        }
        if(tmp > max)
            max = tmp;
    }
    return max;
}
int main() 
{   
    int result;
    int size = 5;
    int nums[5] = {5,4,3,2,1};
    result = findLengthOfLCIS(nums, size);
    printf("%d\n", result);
} 
