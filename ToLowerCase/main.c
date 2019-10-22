#include <stdio.h>

char * toLowerCase(char * str){

    char *res = malloc(strlen(str)+1);
    memset(res, '\0', strlen(str)+1);

    int i;
    for(i=0; i<strlen(str); i++){
        if(str[i]<91 && str[i]>64)
            res[i] = str[i] + 32;
        else
            res[i] = str[i];
    }

    return res;
}


int main(int argc, char *argv[])
{
    char *S = "Hello";
    printf("%s\n",  toLowerCase(S));
}
