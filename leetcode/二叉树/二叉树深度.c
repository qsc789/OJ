//����104
//����һ�������� root �������������ȡ�
//�������� ������ ��ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);//��¼һ�£���ֹʱ�䳬��
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//ȡ�ϴ��һ��
}