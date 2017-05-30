#include <stdio.h>

int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) 
{
	int i,j,x,y;
	int **result;
	if(r*c!=numsRowSize*numsColSize)
	{
		r = numsRowSize;
		c = numsColSize;
	}
	
	*returnSize = r;
	result  = (int**)malloc(sizeof(int *)*r);
	*columnSizes = (int *)malloc(sizeof(int)*r);
	
	for(i=0;i<r;i++)
	{
		result[i] = (int*)malloc(sizeof(int)*c);
		(*columnSizes)[i] = c;
	}
	x = 0;
	y = 0;
	for(i=0;i<numsRowSize;i++)
	{
		for(j=0;j<numsColSize;j++)
		{
			result[x][y] = nums[i][j];
			y++;
			if(y == c)
			{
				x++;
				y = 0;
			}
		}
	}
	return result;
	    
}

int main(int argc, char *argv[])
{
	int **p;
	int returnSize;
	int i,j;
	int **nums;
	int *columnSizes;
	int **s;
	nums  = (int**)malloc(sizeof(int *)*2);
	nums[0]  = (int*)malloc(sizeof(int )*2);
	nums[1]  = (int*)malloc(sizeof(int )*2);
	nums[0][0] = 1;
	nums[0][1] = 2;
	nums[1][0] = 3;
	nums[1][1] = 4;
	p = matrixReshape(nums, 2, 2, 2, 4, &columnSizes, &returnSize);
	for(i=0;i<returnSize;i++)
	{
		for(j=0;j<columnSizes[i];j++)
		{
			printf("%d\n", p[i][j]);
		}
	}
}
