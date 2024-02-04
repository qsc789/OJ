//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
//题目链接：https://leetcode.cn/problems/unique-binary-search-trees
//题解链接：https://leetcode.cn/problems/unique-binary-search-trees/solutions/329807/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/

#include <string.h>
int numTrees(int n) {
    int G[n + 1];
    memset(G, 0, sizeof(G));
    G[0] = G[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}