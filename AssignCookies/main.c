#include <stdio.h>

int findContentChildren(int* g, int gSize, int* s, int sSize) {
 	int res = 0;
    int i;
    int j;
    int y=0;
    int tmp;
    int tmp1;
    for (i= 0; i<sSize; i++)  
    {   
        for (j=i + 1; j < sSize; j++)  
        {
            if (s[i] > s[j])  
            {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }   
    for(i=0;i<sSize;i++)
    {   
        tmp=0;
        for(y=0;y<gSize;y++)
        {
            if(g[y]!=-1&&s[i]>=g[y])
            {
                if(tmp==0 || tmp>g[y])
                {
                    tmp = g[y];
                    tmp1 = y;
                }
            }
        }
        if(tmp!=0)
        {
            res++;
            g[tmp1]=-1;
        }
     }   
    return res;

}

int main(int argc, char *argv[])
{
	int result;
    int len1;
	int len2;
	int g[2] = {1, 2};
    int s[3] = {1, 2, 3};
    len1 = sizeof(g)/sizeof(int);
    len2 = sizeof(s)/sizeof(int);
    result = findContentChildren(g,	len1, s, len2);
    printf("%d\n", result);
}
