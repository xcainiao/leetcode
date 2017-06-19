#include <stdio.h>
/*
        1
       / \
      2   3
     /   / \
    4   5   6
   / \  /   / \
  7  8  9  10  11

        3
       /  \
      1    5
     / \   / \
    0   2 4   6
          
           
*/
typedef struct TreeNode  {
 int val;
 struct TreeNode  *left;
 struct TreeNode  *right;
} treeNode, *ptreeNode;


treeNode* createNode(int val)
{
    ptreeNode node; 
    node = (ptreeNode)malloc(sizeof(treeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
treeNode* createTree()
{
    ptreeNode p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
    p1 = createNode(3);
    p2 = createNode(1);
    p3 = createNode(5);
    p4 = createNode(0);
    p5 = createNode(2);
    p6 = createNode(4);
    p7 = createNode(6);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    return p1;
}

int i = 0;
void postorder(struct TreeNode* root, int* result, int* returnSize, int flag)
{
    if(!flag)
        i = 0;
    if(root)
    {
        //printf("%d\n", root->val);
        *returnSize = *returnSize + 1;
        postorder(root->left, result, returnSize, 1);
        postorder(root->right, result, returnSize, 1);
        result[i] = root->val;
        i++;
    }
}

int* postorderTraversal(struct TreeNode* root,  int* returnSize) 
{
    int *result;
    *returnSize = 0;
    result = (int*)malloc(10000);
    postorder(root, result, returnSize, 0);
    for(i=0;i<*returnSize;i++)
    {
        printf("%d\n", result[i]); 
    }
    return result;
}


int main() 
{   
    int i;
    int size;
    int *result;
    ptreeNode tree;
    tree = createTree();
    postorderTraversal(tree, &size);
} 
