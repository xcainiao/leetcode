#include <stdio.h>
#define bool int
int searchInsert(int* nums, int numsSize, int target) 
{
   int i;
   int result = -1;
   for(i=0;i<numsSize;i++)
   {
        if(nums[i]<target)
        {
            result = i + 1;
        }
        if(nums[i]==target)
            return i;
   }
   if(result==-1)
       return 0;
   else
       return result;
}
int main() 
{   
    int result;
    int num[4] = {1, 3};
    result = searchInsert(num, 2, 2);
    printf("%d\n", result);
} 
