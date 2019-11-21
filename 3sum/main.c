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
	res = (int **)malloc(sizeof(int *)*numsSize);
	rres = (int **)malloc(sizeof(int *)*numsSize);

	*returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);

	for(i=0; i<numsSize; i++){
		for(j=i+1; j<numsSize; j++){
			for(k=j+1; k<numsSize; k++){
				if(nums[i]+nums[j]+nums[k]==0){
					compare(tmp, nums[i], nums[j], nums[k]);
					res[*returnSize] = (int *)malloc(sizeof(int)*10);
					res[*returnSize][0] = tmp[0];
					res[*returnSize][1] = tmp[1];
					res[*returnSize][2] = tmp[2];
					(*returnSize)++;
				}
			}
		}
	
	}
	printf("%d\n", *returnSize);
	for(i=0; i<(*returnSize); i++){
		for(j=i+1; j<(*returnSize); j++){
			if(res[i][0] == res[j][0] && res[i][1] == res[j][1] && res[i][2] == res[j][2]){
				printf("%d\n", i);
				free(res[i]);
				res[i] = NULL;
				/*
				xx++;
				*/
			}
		}
	}
	
	/*
	for(i=0; i<*returnSize; i++){
		if(res[i]){
			rres[xx2] = res[i];
			(*returnColumnSizes)[xx2] = 3;
			xx2++;
		}
	}

	*returnSize = *returnSize - xx;
	*/

	return rres;
}

int main(int argc, char *argv[])
{
	int **res;
	int nums[] = {0, 0, 0, 0};
	int returnSize;
	int *returnCo;
	int i, j;

	res = threeSum(nums, 4, &returnSize, &returnCo);
	/*
	for(i=0; i<returnSize; i++){
		for(j=0; j<returnCo[i]; j++){
			printf("%d \t", res[i][j]);
		}
		printf("\n");
	}
	*/

}
