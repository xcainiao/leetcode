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
struct ListNode* removeElements(struct ListNode* head, int val) 
{
   struct ListNode* tmppre;
   struct ListNode* tmp;
   if(!head)
       return NULL;
   while(head&&head->val==val)
   {
        head = head->next;
   }
   if(head)
   {
       tmppre = head;
       tmp = head->next;
       while(tmp)
       {
           if(tmp->val == val)
           {
                tmppre->next = tmp->next;
                tmp = tmp->next;

           }
           else
           {
                tmppre = tmp;
                tmp = tmp->next;
           }
       }
   }
   return head;
}
int main() 
{     
    struct ListNode *l1;
    struct ListNode *l1_1;
    struct ListNode *l1_2;
    struct ListNode *l1_3;
    
    
    struct ListNode *result;
    
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = l1_1;
    l1_1->val = 8;
    l1_1->next = l1_2;
    l1_2->val = 1;
    l1_2->next = l1_3;
    l1_3->val = 8;
    l1_3->next = NULL;
    result = removeElements(l1, 1);
    while(result)
    {
        printf("%d\n", result->val);
        result = result->next;
    }
} 
