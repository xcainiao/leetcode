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
void inorder(struct TreeNode* root, int* result, int* returnSize, int flag)
{
    if(!flag)
        i = 0;
    if(root)
    {
        *returnSize = *returnSize + 1;
        inorder(root->left, result, returnSize, 1);
        result[i] = root->val;
        i++;
        //printf("%d\n", root->val);
        inorder(root->right, result, returnSize, 1);
    }
}

int inorderTraversal(struct TreeNode* root, int k) 
{
    int x, y;   
    int *result;
    int returnSize;
    returnSize = 0;
    result = (int*)malloc(10000);
    inorder(root, result, &returnSize, 0);
    for(x=0;x<returnSize;x++)
    {
        for(y=x+1;y<returnSize;y++)
        {
            if((result[x] + result[y]) == k)
                return 1;
            //printf("%d\n", (result[x] + result[y]));
        }
    }
    return 0;
}


int main() 
{   
    int i;
    int size;
    int *result;
    ptreeNode tree;
    tree = createTree();
    printf("%d\n", inorderTraversal(tree, 20));
} 
