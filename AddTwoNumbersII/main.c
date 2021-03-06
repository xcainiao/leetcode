#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
int countList(struct ListNode* l)
{
    struct ListNode *tmp;
    int count = 0;
    tmp = l;
    while(tmp)
    {
        tmp = tmp->next;
        count++;
    }
    return count; 
}
int max(int num1, int num2)
{
    return num1>num2?num1:num2;
}
void addList(struct ListNode* l, int val)
{
    struct ListNode* tmp;
    struct ListNode* tmp1;
    tmp = l;
    while(tmp->next)
    {
        tmp = tmp->next;
    }
    tmp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp1->next = NULL;
    tmp1->val = val;
    tmp->next = tmp1;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *tmp1;
    struct ListNode *tmp2;
    struct ListNode *resultlist;
    int count = 0;
    int tmpsum = 0;
    int divide = 0;
    int i = 0;
    int result[10000];
    int size = 0;
    tmp1 = l1;
    tmp2 = l2;
    for(i=0;i<10000;i++)
        result[i] = 0;
    count = max(countList(l1), countList(l2));
    for(i=0;i<count+1;i++)
    {
       tmp1 = l1;
       tmp2 = l2;
       while(tmp1->next&&tmp1->next->val>=0)
       {
           tmp1 = tmp1->next;
       }
       while(tmp2->next&&tmp2->next->val>=0)
       {
            tmp2 = tmp2->next;
       }
       if(tmp1->val<0)
            tmp1->val = 0;
       if(tmp2->val<0)
            tmp2->val = 0;
       tmpsum = tmp1->val+tmp2->val+divide;
       divide = tmpsum/10;
       tmpsum = tmpsum%10;
       result[size] = tmpsum;
       size++;
       //printf("%d\n", tmpsum);
       tmp1->val = -1;
       tmp2->val = -1;
    }
    resultlist = (struct ListNode*)malloc(sizeof(struct ListNode));
    resultlist->next = NULL;
    if(result[size-1])
    {
        resultlist->val = result[size-1];
        for(i=size-2;i>=0;i--)
        {
            addList(resultlist, result[i]);
            //printf("%d\n", result[i]);
        }
    }
    else
    {
        resultlist->val = result[size-2];
        for(i=size-3;i>=0;i--)
        {
            //printf("%d\n", result[i]);
            addList(resultlist, result[i]);
        }
    }
    return resultlist;
}

int main() 
{     
    struct ListNode *l1;
    struct ListNode *l1_1;
    struct ListNode *l1_2;
    
    struct ListNode *l2;
    struct ListNode *l2_1;
    struct ListNode *l2_2;
    
    struct ListNode *result;
    
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 8;
    l1->next = l1_1;
    l1_1->val = 7;
    l1_1->next = l1_2;
    l1_2->val = 5;
    l1_2->next = NULL;
    
    l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 9;
    l2->next = l2_1;
    l2_1->val = 0;
    l2_1->next = l2_2;
    l2_2->val = 1;
    l2_2->next = NULL;
    result = addTwoNumbers(l1, l2);
    while(result)
    {
        printf("%d\n", result->val);
        result = result->next;
    }
} 
