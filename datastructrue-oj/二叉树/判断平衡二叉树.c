//����110
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//�����У�һ�ø߶�ƽ�����������Ϊ��
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��

int maxDepth(struct TreeNode* root) {//��ÿ���ڵ��������������
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);//ע��ݹ�����
    //abs�����ֵ
}