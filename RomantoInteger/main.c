#include <stdio.h>

int romanToInt(char* s) 
{
      int map[256] = {0};
      int i;
      int nums;
      int sum = 0;
      map['I'-'A'] = 1;
      map['V'-'A'] = 5;
      map['X'-'A'] = 10; 
      map['L'-'A'] = 50; 
      map['C'-'A'] = 100;
      map['D'-'A'] = 500;
      map['M'-'A'] = 1000;
      nums = strlen(s);
      
      for(i=0;i<nums;)
      {   
          if(i!=nums-1&&map[s[i+1]-'A']>map[s[i]-'A'])
          {
              sum = sum + map[s[i+1]-'A'] - map[s[i]-'A'];
              i = i+2;
          }
          else
          {
              sum = sum + map[s[i]-'A'];
              i = i+1;
          }
      }
      
      return sum;
}

int main(int argc, char *argv[])
{
	int result;
	char s[] = "IV";
	result = romanToInt(s);
	printf("%d\n", result);
}
