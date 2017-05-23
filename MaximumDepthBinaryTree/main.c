#include <stdio.h>

int maxDepth(struct TreeNode* root) 
{
    int left = 1;
    int right = 1;
    struct TreeNode* tmp;
    if(root == NULL)
        return NULL;
    if(root->left)
    {
        tmp = root->left;
        left = maxDepth(tmp);
        left++;
    }
    if(root->right)
    {
        tmp = root->right;
        right = maxDepth(tmp);
        right++;
    }
    return left>right?left:right;

}

int main(int argc, char *argv[])
{
}
