//力扣144
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _prevOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    a[*pi] = root->val;
    (*pi)++;
    _prevOrder(root->left, a, pi);
    _prevOrder(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * size);
    int i = 0;
    _prevOrder(root, a, &i);//i的值变化，传地址

    *returnSize = size;//输出参数
    return a;
}