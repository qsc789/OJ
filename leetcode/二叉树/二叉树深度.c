//力扣104
//给定一个二叉树 root ，返回其最大深度。
//二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);//记录一下，防止时间超限
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//取较大的一侧
}