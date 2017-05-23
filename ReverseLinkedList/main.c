#include <stdio.h>

struct ListNode* reverseList(struct ListNode* head) 
{
       struct ListNode* newp = NULL;
       struct ListNode* tmp1 = NULL;
       struct ListNode* tmp2 = NULL;
       for(tmp1=head;tmp1;)
       {
           tmp2 = tmp1->next;
           tmp1-> next = newp;
           newp = tmp1;
           tmp1 = tmp2;
           
       }
       return newp;
}

int main(int argc, char *argv[])
{
}
