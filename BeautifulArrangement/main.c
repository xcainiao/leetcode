#include <stdio.h>

int count = 0;
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int perm(int list[], int k, int m,int* result)
{
    int i;
    int tmp = 0;
	if(k > m)
	{
	    for(i = 0; i <= m; i++)
        {
            if(((i+1)%list[i])!=0 && (list[i]%(i+1)!=0))
                break;
            tmp++;
        }
        if(tmp == m+1)
        {
            count = count +1;
            //*result = *result + 1;
        }
    }
	else
	{
		for(i = k; i <= m; i++)         
        {             
            swap(&list[k], &list[i]);             
            perm(list, k + 1, m, result);             
            swap(&list[k], &list[i]);
        }  
	}
}
int countArrangement(int N)
{
    int list[N];
    int i;
    int *result;
    result = (int *)malloc(sizeof(int));
    *result = 0;
    for(i=0;i<N;i++)
    {
        list[i] = i+1;
    }
    perm(list, 0, N-1, result);
    return *result;
}
int main() 
{     
    int result;
    result = countArrangement(13);
    printf("%d\n", count);
    return 0; 
} 
/*
int main()
{
    int N = 3;
    perm(1, N);
*/
/*
void perm(N)
{
    int i;
    int j;
    int k;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            for(k=1;k<=N;k++)
            {
                if(j!=i && k!=i && k!=j)
                    printf("%d %d %d ", i, j, k);
            }
        }
        printf("\n");
    }
}
*/
