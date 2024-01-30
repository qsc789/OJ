//力扣101
//给你一个二叉树的根节点 root ， 检查它是否轴对称。
bool Check(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->val == root2->val)
    {
        return Check(root1->left, root2->right) && Check(root1->right, root2->left);
    }
    else
        return false;
}
bool isSymmetric(struct TreeNode* root) {
    return Check(root, root);
}