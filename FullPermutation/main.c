#include <stdio.h>

int a[3] = {0};
int count = 0;
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void perm(int list[], int k, int m)
{
    int i;
    int tmp = 0;
	if(k > m)
	{
	    for(i = 0; i <= m; i++)
        {
            printf("%d ", list[i]);
        }
        printf("\n");
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
}
int main() 
{     
    int list[] = {1};     
    perm(list, 0, 0);     
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
