#include <stdio.h>

void clear(int a[])
{
    int i;
    for(i=0;i<2;i++)
    {
        a[i] = -1;
    }
}
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) 
{
    int i,j;
    int index = 1000;
    char **result;
    int tmp[1000];
    clear(tmp);
    *returnSize = 0;
    for(i=0;i<list1Size;i++)
    {
        for(j=0;j<list2Size;j++)
        {
           if(!strcmp(list1[i], list2[j]))
           {
               if(index>(i+j))
               {
                    index = (i+j);
                    clear(tmp);
                    (*returnSize) = 1;
                    tmp[(*returnSize)-1] = i;
               }
               else if(index==(i+j))
               {
                    *returnSize = *returnSize + 1;
                    tmp[(*returnSize)-1] = i;
               }
           }
        }
    }
    //printf("%d\n", *returnSize);
    result = (char**)malloc(sizeof(char*)*(*returnSize));
    for(i=0;i<*returnSize;i++)
    {
        result[i] = (char *)malloc(sizeof(char)*strlen(list1[tmp[i]]));
        strcpy(result[i], list1[tmp[i]]);
        //printf("%d\n", tmp[i]);     
    }
    return result;
}
int main() 
{     
    char **result;
    char **list1;
    char **list2;
   
    int list1Size = 4;
    int list2Size = 4;
    
    int returnSize;

    list1 = (char**)malloc(sizeof(char*)*4);
    list1[0] = (char *)malloc(sizeof(char)*7);
    list1[0] = "shogun";
    list1[1] = (char *)malloc(sizeof(char)*4);
    list1[1] = "kfc";
    list1[2] = (char *)malloc(sizeof(char)*5);
    list1[2] = "king";
    list1[3] = (char *)malloc(sizeof(char)*5);
    list1[3] = "kin2";
    

    list2 = (char**)malloc(sizeof(char*)*4);
    list2[0] = (char *)malloc(sizeof(char)*5);
    list2[0] = "kin2";
    list2[1] = (char *)malloc(sizeof(char)*5);
    list2[1] = "king";
    list2[2] = (char *)malloc(sizeof(char)*4);
    list2[2] = "kfc";
    list2[3] = (char *)malloc(sizeof(char)*7);
    list2[3] = "shogun";
    
    findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
} 
