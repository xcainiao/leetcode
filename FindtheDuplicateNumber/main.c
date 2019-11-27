#include <stdio.h>

//普通方法 o(n(n-1))
int findDuplicate2(int* nums, int numsSize){
    int i, j;
    
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return nums[i];
            }
        }            
    }
    
    return -1;
}

//二分法
int findDuplicate(int* nums, int numsSize){
    int mid=0, i=0;
    int x=1, y=numsSize;
    int left=0;
    while (y>x) {
        mid = (y-x)/2 + x;
        left = 0;
        for(i=0; i<numsSize;i++){
                if(nums[i]<=mid)
                    left++;
        }
        if(left>mid){
            y = mid;
        }
        else{
            x = mid + 1;
        }
    }
    return x;
}

int main(int argc, char *argv[])
{
    int res;
    int N = 5;
    int nums[] = {3,1,3,4,2};
    res = findDuplicate(nums, N);
    printf("%d\n",  res);
}
