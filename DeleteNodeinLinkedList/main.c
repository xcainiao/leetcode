#include <stdio.h>

void deleteNode(struct ListNode* node) 
{
    while(node->next !=NULL)
    {
        node->val = node->next->val;
        if(node->next->next==NULL)
        {
            node->next = NULL;
            break;
        }
        else
            node = node->next;
    }
}

int main(int argc, char *argv[])
{
}
