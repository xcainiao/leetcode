#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *detectCycle(struct ListNode *head) 
{
    int i,j;
    int tmpadd[10000];
    struct ListNode *tmp;
    for(i=0;i<10000;i++)
    {   
        tmpadd[i] = NULL;
    }   
    tmp = head;
    i = 0;
    while(tmp)
    {   
        tmpadd[i] = tmp;
        tmp = tmp->next;
        for(j=0;j<=i;j++)
        {
            if(tmpadd[j] == tmp)
                return tmp;
        }
        i++;
    }   
    return NULL;   
}

int main() 
{     
    struct ListNode *l1;
    struct ListNode *l1_1;
    struct ListNode *l1_2;
   
    
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 8;
    l1->next = l1_1;
    l1_1->val = 7;
    l1_1->next = l1_2;
    l1_2->val = 5;
    l1_2->next = l1;
    
	detectCycle(l1);
} 
