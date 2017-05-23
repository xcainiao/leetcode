#include <stdio.h>

int longestPalindrome(char* s) {
	  int i;
      int t[58] = {0};
      int res = 0;
      int x = 0;
      for(i=0;s[i]!=NULL;i++)
      {   
          t[s[i]-'A']++;
      }   
      for(i=0;i<58;i++)
      {   
          if(t[i]>1)
          {
              res = res + t[i]/2*2;
          }
          if(t[i]%2!=0)
              x = 1;
      }   
      res = res + x;
      return res;
}

int main(int argc, char *argv[])
{
	int result;
	char s[] = "abccccdd";
	result = longestPalindrome(s); 
	printf("%d\n", result);
}
