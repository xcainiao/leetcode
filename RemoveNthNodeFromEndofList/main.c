#include <stdio.h>

/**
 * Definition for singly-linked list.
 */

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int i = 0;
    int length = 0;
    struct ListNode *tmp;
    tmp = head;
    while(tmp){
        tmp = tmp->next;
        length++;
    }

    if(length==1)
        return '\0';
    if(length==n)
        return head->next;

    tmp = head;
    while(tmp){
        i++;
        if(i == (length-n)){
            tmp->next = tmp->next->next;
        }
        tmp = tmp->next;
    }
    return head;
}

int main(int argc, char *argv[])
{
    struct ListNode *res;
    struct ListNode *head;

    struct ListNode *l1;
    struct ListNode *l2;
    struct ListNode *l3;
    struct ListNode *l4;
    struct ListNode *l5;

    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l5 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 1;
    l1->next = l2;
    l2->val = 2;
    l2->next = l3;
    l3->val = 3;
    l3->next = l4;
    l4->val = 4;
    l4->next = l5;
    l5->val = 5;
    l5->next = '\0';
    
    head = l1;

    res = removeNthFromEnd(head, 5);

    while(res){
        printf("%d\n", res->val);
        res = res->next;
    }

}
