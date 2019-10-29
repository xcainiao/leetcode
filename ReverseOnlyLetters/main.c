#include <stdio.h>

char * reverseOnlyLetters(char * S){
    char *res;
    int i, j;
    int length;
    length = strlen(S);
    j = length -1;
    res = malloc(length+1);
    for(i=0; i<length; i++){
        if((S[i]>='A' && S[i]<='Z') || (S[i]>='a' && S[i]<='z')){
            while(!((S[j]>='A' && S[j]<='Z') || (S[j]>='a' && S[j]<='z'))){
                j--;
            }
            res[i] = S[j];
            j--;
        }
        else{
            res[i] = S[i];
        }
    }
    res[length] = '\0';
    return res;
}


int main(int argc, char *argv[])
{
    char *res;
    char *S = "Test1ng-Leet=code-Q!";
    res = reverseOnlyLetters(S);
    printf("%s\n",  res);
}
