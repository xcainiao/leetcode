#include <stdio.h>

int singleNumber(int A[], int n) {
    int result = 0;
    for (int i = 0; i<n; i++)
    {
		result ^=A[i];
    }
	return result;
}

int main(int argc, char *argv[])
{
	int A[5] = {1,1,6,3,3};
	int length;
    int result;
    length = sizeof(A)/sizeof(int);
    result = singleNumber(A, length); 
    printf("%d\n", result);
}
