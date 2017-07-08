#include <stdio.h>
#define bool int
void removeOne(int *nums, int start, int n, int numsSize)
{
   int i;
   for(i=start+1;i<=numsSize-n;i++)
   {
        nums[i] = nums[i+n-1];
   }
}
int removeDuplicates(int* nums, int numsSize)
{
    
    int i;
    int j;
    int k;
    int returnSize = numsSize;
    for(i=0;i<returnSize-1;i++)
    {
        j = i+1;
        while(nums[i]==nums[j] && j<numsSize)
        {
            j++;
            returnSize--;
        }
        removeOne(nums, i, j-i, numsSize);
        numsSize = returnSize;
     }
    for(i=0;i<returnSize;i++)
    {
        printf("%d\n", nums[i]);
    }
    return numsSize;
}
int main() 
{   
    int result;
    int nums[5] = {1,1,1,1,1}; 
    result = removeDuplicates(nums, 5);
    //printf("%d\n", result);
} 
