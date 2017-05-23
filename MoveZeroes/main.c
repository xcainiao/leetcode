#include <stdio.h>

void movezeroes(int* nums, int numsSize) {
    int *p = nums;
    int i;
    int x=0;
    for(i=0;i<numsSize;i++)
    {   
        if(p[i]!=0)
        {
           nums[x] = p[i];
           x++;
        }
    }   
    for(i=x;i<numsSize;i++)
    {   
           nums[i] = 0;
    }   
}

int main(int argc, char *argv[])
{
	int i;
    int result;
	int length;
    int nums[5] = {0, 1, 0, 3, 12}; 
    length = sizeof(nums)/sizeof(int);
    movezeroes(nums, 5);
    for(i=0;i<5;i++)
    {
        printf("%d\n", nums[i]);
    }
}
