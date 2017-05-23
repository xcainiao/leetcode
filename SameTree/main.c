#include <stdio.h>

bool isSameTree(struct TreeNode* p, struct TreeNode* q) 

{

    if(p == NULL && q == NULL)
        return 1;
    if(p == NULL && q != NULL)
        return 0;
    if(p != NULL && q == NULL)
        return 0;
    if(p->val != q->val)
        return 0;
    if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
}
