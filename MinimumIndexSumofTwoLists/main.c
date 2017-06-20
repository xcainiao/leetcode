#include <stdio.h>
int min(int i, int j)
{
    return i<j?i:j;
}
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
    int tmp[2];
    clear(tmp);
    *returnSize = 0;
    for(i=0;i<list1Size;i++)
    {
        for(j=0;j<list2Size;j++)
        {
           if(!strcmp(list1[i], list2[j]))
           {
               if(index>min(i,j))
               {
                    index = min(i,j);
                    clear(tmp);
                    (*returnSize) = 1;
                    tmp[(*returnSize)-1] = i;
                    continue;
               }
               if(index==min(i,j))
               {
                    if(*returnSize!=1)
                        clear(tmp);
                    *returnSize = *returnSize + 1;
                    tmp[(*returnSize)-1] = i;
               }
           }
        }
    }
    result = (char**)malloc(sizeof(char*)*(*returnSize));
    for(i=0;i<*returnSize;i++)
    {
        result[i] = (char *)malloc(sizeof(char)*strlen(list1[tmp[i]]));
        strcpy(result[i], list1[tmp[i]]);
        printf("%s\n", result[i]);     
    }
    return result;
}
int main() 
{     
    char **result;
    char **list1;
    char **list2;
   
    int list1Size = 3;
    int list2Size = 3;
    
    int returnSize;

    list1 = (char**)malloc(sizeof(char*)*3);
    list1[0] = (char *)malloc(sizeof(char)*7);
    list1[0] = "shogun";
    list1[1] = (char *)malloc(sizeof(char)*4);
    list1[1] = "kfc";
    list1[2] = (char *)malloc(sizeof(char)*5);
    list1[2] = "king";
    

    list2 = (char**)malloc(sizeof(char*)*3);
    list2[0] = (char *)malloc(sizeof(char)*7);
    list2[0] = "kfc";
    list2[1] = (char *)malloc(sizeof(char)*4);
    list2[1] = "shogun";
    list2[2] = (char *)malloc(sizeof(char)*4);
    list2[2] = "fck";
    
    findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
} 
