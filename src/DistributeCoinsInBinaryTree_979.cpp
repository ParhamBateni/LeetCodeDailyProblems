/*
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.
 */
#include "../utils.h"
#include "gtest/gtest.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution979 : public ::testing::Test {
public:
    static int distributeCoins(TreeNode *root, TreeNode *parent = NULL) {
        if (!root)
            return 0;
        int moves = distributeCoins(root->left, root) +
                    distributeCoins(root->right, root);
        int x = root->val - 1;
        if (parent)
            parent->val += x;
        moves += abs(x);
        return moves;
    }
};


TEST(Solution979, T1) {
    TreeNode t1 = TreeNode(0);
    TreeNode t2 = TreeNode(0);
    TreeNode t3 = TreeNode(3, &t1, &t2);
    ASSERT_EQ(2, Solution979::distributeCoins(&t3));
}

TEST(Solution979, T2) {
    TreeNode t1 = TreeNode(0);
    TreeNode t2 = TreeNode(3);
    TreeNode t3 = TreeNode(0, &t1, &t2);
    ASSERT_EQ(3, Solution979::distributeCoins(&t3));
}