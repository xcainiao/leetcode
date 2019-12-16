#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    int i, j;
    char *res;
    int tmp = 100000, len = 0;

    if(strsSize==0)
        return "";

    if(strsSize==1)
        return strs[0];


    for(i=0; i<strsSize; i++){
        len = strlen(strs[i]);
        if(len<tmp){
            tmp = len;
        }
    }

    res = (char *)malloc(tmp+1);
    res[0] = '\0';

    for(i=0; i<tmp; i++){
        j = 0;
        while(j<strsSize-1){
            if((strs[j][i] - strs[j+1][i]) !=0){
                goto end;
            }
            j++;
        }
    }

    end:
        for(j=0; j<i; j++){
            res[j] = strs[0][j];
        }
        res[j] = '\0';
        return res;
}

int main(int argc, char *argv[])
{
    char *res;
    char *str[1] = {""};
    res = longestCommonPrefix(str, 1);
    printf("%s\n",  res);
}
