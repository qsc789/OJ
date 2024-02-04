//牛客BM32
// https://www.nowcoder.com/practice/7298353c24cc42e3bd5f0e0bd3d1d759?tpId=295&tqId=1025038&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
//已知两颗二叉树，将它们合并成一颗二叉树。合并规则是：都存在的结点，就将结点值加起来，否则空的位置就由另一个树的结点来代替
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param t1 TreeNode类
  * @param t2 TreeNode类
  * @return TreeNode类
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
        node = CreateNode(t2->val);//一个节点已经为空，这个节点的左右子树直接赋值为非空节点的左右子树
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