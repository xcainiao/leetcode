#include <stdio.h>


void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int perm(int list[], int k, int m)
{
    static int count = 0;
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
            count++;
        }
    }
	else
	{
		for(i = k; i <= m; i++)         
        {             
            swap(&list[k], &list[i]);             
            perm(list, k + 1, m);             
            swap(&list[k], &list[i]);
        }  
	}
    return count;
}
int countArrangement(int N)
{
    int list[N];
    int i;
    for(i=0;i<N;i++)
    {
        list[i] = i+1;
    }
    return perm(list, 0, N-1);     
}
int main() 
{     
    int result;
    result = countArrangement(1);
    printf("%d\n", result);
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
