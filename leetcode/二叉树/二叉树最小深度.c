//����111
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/
//����һ�����������ҳ�����С��ȡ�
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
//˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int min_depth = INT_MAX;//��һ��������
    if (root->left != NULL)
    {
        min_depth = fmin(minDepth(root->left), min_depth);//ȡ��Сֵ
    }
    if (root->right != NULL)
    {
        min_depth = fmin(minDepth(root->right), min_depth);
    }
    return min_depth + 1;
}