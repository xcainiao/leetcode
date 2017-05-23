#include <stdio.h>

char** readBinaryWatch(int num, int* returnSize) 
{
      int h0[] = {0,-1};
      int h1[] = {1,2,4,8,-1};
      int h2[] = {3,5,9,6,10,-1};
      int h3[] = {7,11,-1};
  
      int m0[] = {0,-1};
      int m1[] = {1,2,4,8,16,32,-1};
      int m2[] = {3,5,9,17,33,6,10,18,34,12,20,36,24,40,48,-1};
      int m3[] = {7,11,19,35,14,22,37,38,28,44,56,13,21,25,26,41,42,49,50,52,-1};
      int m4[] = {15,23,39,30,46,27,29,43,45,51,53,54,57,58,-1};
      int m5[] = {31,47,55,59,-1};
  
      int *h[] = {h0,h1,h2,h3};
      int *m[] = {m0,m1,m2,m3,m4,m5};
  
      int i;
      int j;
      int k;
      int x;
      int len;
      int returns = 0;
      char **returnp;
      char htmp[2];
      char mtmp[2];
      char tmp[6];
      for(i=0;i<=num;i++)
      {
          j=num-i;
          if(i<4&&j<6)
          {
              for(x=0;h[i][x]!=-1;x++)
              {
                  for(k=0;m[j][k]!=-1;k++)
                  {
                      returns++;
                  }
              }
          }
      }
      *returnSize = returns;
      returnp = (char **)malloc(sizeof(char*)*returns);
      memset(tmp, 0, 5);
      for(i=0;i<=num;i++)
      {
          j=num-i;
          if(i<4&&j<6)
          {
              for(x=0;h[i][x]!=-1;x++)
              {
                  memset(htmp, 0, 2);
                  sprintf(htmp, "%d", h[i][x]);
                  for(k=0;m[j][k]!=-1;k++)
                  {
                      memset(mtmp, 0, 2);
                      if(m[j][k]<10)
                      {
                          strcpy(mtmp,"0");
                          sprintf(mtmp+1, "%d", m[j][k]);
                      }
                      else
                      {
                          sprintf(mtmp, "%d", m[j][k]);
                      }
                      strcpy(tmp, htmp);
                      strcat(tmp, ":");
                      strcat(tmp, mtmp);
                      returns--;
                      returnp[returns] = malloc(sizeof(tmp));
                      strcpy(returnp[returns], tmp);
                  }
              }
          }
      }
      return returnp;
}


int main(int argc, char *argv[])
{
	int i;

    char **result;
    int num = 1;
	int returnSize;
	result = readBinaryWatch(num, &returnSize);
    for(i=0;i<returnSize;i++)
    {
        printf("%s\n", result[i]);
    }
}
