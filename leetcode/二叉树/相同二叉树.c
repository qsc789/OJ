//����100
//https://leetcode.cn/problems/same-tree
//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p == NULL || q == NULL)
    {
        return false;
    }

    else if (p->val != q->val)
    {
        return false;
    }
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);


}