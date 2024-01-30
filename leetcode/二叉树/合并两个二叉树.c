//ţ��BM32
// https://www.nowcoder.com/practice/7298353c24cc42e3bd5f0e0bd3d1d759?tpId=295&tqId=1025038&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
//��֪���Ŷ������������Ǻϲ���һ�Ŷ��������ϲ������ǣ������ڵĽ�㣬�ͽ����ֵ������������յ�λ�þ�����һ�����Ľ��������
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param t1 TreeNode��
  * @param t2 TreeNode��
  * @return TreeNode��
  */
struct TreeNode* CreateNode(int val)
{
    struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val = val;
    return newnode;
}
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    struct TreeNode* node = NULL;
    if (t1 == NULL && t2 == NULL)
    {
        return NULL;
    }
    else if (t1 == NULL && t2 != NULL)
    {
        node = CreateNode(t2->val);//һ���ڵ��Ѿ�Ϊ�գ�����ڵ����������ֱ�Ӹ�ֵΪ�ǿսڵ����������
        node->left = t2->left;
        node->right = t2->right;
    }
    else if (t1 != NULL && t2 == NULL)
    {
        node = CreateNode(t1->val);
        node->left = t1->left;
        node->right = t1->right;
    }
    else if (t1 != NULL && t2 != NULL)
    {
        node = CreateNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
    }

    return node;



}