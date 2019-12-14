#include <stdio.h>

/*
 *  个位数 0和非0
 *
 *  非个位数 1开头 全部 2开头 小于7 
 *
 *  动态规划
 *  dp
 */

int numDecodings(char * s){
    int i;
    int length;
    length = strlen(s);

    int *dp;
    dp = (int *)malloc(sizeof(int)*(length+1));
    
    for(i=0;i<=length;i++){
        dp[i] = 0;
    }

    if(s[0]=='0')
        return 0;

    dp[0] = 1;
    dp[1] = 1;


    for(i=2; i<=length; i++){
        if(s[i-1]!='0'){
            dp[i] = dp[i] + dp[i-1];
        }
        if(s[i-2]=='1'){
            dp[i] = dp[i] + dp[i-2];
        }
        if(s[i-2]=='2' && s[i-1]<'7'){
            dp[i] = dp[i] + dp[i-2];
        }
    }
    return dp[length];
}

int main(int argc, char *argv[])
{
    int res;
    char S[] = "226";
    res = numDecodings(S);
    printf("%d\n",  res);
}
