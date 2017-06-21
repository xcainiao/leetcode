#include <stdio.h>
#define bool int
int removeElement(int* nums, int numsSize, int val) 
{
   int i,j;
   int k = 0;
   for(i=0;i<numsSize;)
   {
        j = i;
        while(nums[j]==val)
        {
            j++;
        }
        if(j<numsSize)
        {
            //printf("%d\n", nums[j]);
            nums[k] = nums[j];
            k++;
        }
        i = j+1;
   }
   for(i=0;i<k;i++)
   {
        printf("%d\n", nums[i]);
   }
   return k;
}
int main() 
{   
    int result;
    int nums[5] = {1,3,3,3,1}; 
    result = removeElement(nums, 5, 3);
    //printf("%d\n", result);
} 
