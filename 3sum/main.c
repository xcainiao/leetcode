#include <stdio.h>


void compare(int *tmpx, int a, int b, int c){
	int tmp;
	if(a<b){
		tmp = a;
		a=b;
		b=tmp;
	}
	if(a<c){
		tmp=a;
		a=c;
		c=tmp;
	}
	if(b<c){
		tmp=b;
		b=c;
		c=tmp;
	}
	tmpx[0] = a;
	tmpx[1] = b;
	tmpx[2] = c;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i, j, k;
	int **res;
	int **rres;
	int tmp[3];
	int xx = 0;
	int xx2 = 0;
	*returnSize = 0;
	res = (int **)malloc(sizeof(int *)*(numsSize + 1) * 60);
	rres = (int **)malloc(sizeof(int *)*(numsSize + 1) * 60);

	*returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);

	for(i=0; i<numsSize; i++){
		for(j=i+1; j<numsSize; j++){
			for(k=j+1; k<numsSize; k++){
				if(nums[i]+nums[j]+nums[k]==0){
					compare(tmp, nums[i], nums[j], nums[k]);
					res[*returnSize] = (int *)malloc(sizeof(int)*3);
					res[*returnSize][0] = tmp[0];
					res[*returnSize][1] = tmp[1];
					res[*returnSize][2] = tmp[2];
					(*returnSize)++;
				}
			}
		}

	}
	for(i=0; i<*returnSize; i++){
		for(j=i+1; j<*returnSize; j++){
			if(res[i][0] == res[j][0] && res[i][1] == res[j][1] && res[i][2] == res[j][2]){
				free(res[i]);
				res[i] = 0;
				xx++;
				break;
			}
		}
	}


	for(i=0; i<*returnSize; i++){
		if(res[i]){
			rres[xx2] = res[i];
			(*returnColumnSizes)[xx2] = 3;
			xx2++;
		}
	}

	*returnSize = *returnSize - xx;

	return rres;
}

int main(int argc, char *argv[])
{
	int **res;
	int nums[] = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
	int returnSize;
	int *returnCo;
	int i, j;

	res = threeSum(nums, 108, &returnSize, &returnCo);
	for(i=0; i<returnSize; i++){
		for(j=0; j<returnCo[i]; j++){
			printf("%d \t", res[i][j]);
		}
		printf("\n");
	}

}
