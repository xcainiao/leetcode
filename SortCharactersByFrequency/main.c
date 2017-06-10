#include <stdio.h>

char* frequencySort(char* s) 
{
    int i;
    int j = 0;
    int length;
    char *result;
    char *r_result;
    int count = 1;
    int size = 0;
    length = strlen(s);
    int tmp[100];
    for(i=0;i<100;i++)
    {
       tmp[i] = 0;
    }
    result = (char *)malloc(sizeof(char)*length);
    
    for(i=0;i<length;i++)
    {
        tmp[s[i]-' ']++;
    }
    count = length;
    for(j=0;j<length;j++)
    {
        for(i=0;i<100;i++)
        {
            if(tmp[i] == count)
            {
                while(tmp[i]>0)
                {
                    result[size] = i + ' ';
                    size++;
                    tmp[i]--;
                }
            }
        }
        count--;
    }
    result[size] = NULL;
    return result;
}

int main(int argc, char *argv[])
{
    char* result;
    //char s[] = "2a554442f544asfasssffffasss";
    char s[] = "eeeelloocdtva he  ha ae";
    result = frequencySort(s);
    printf("%s\n", result);
}
