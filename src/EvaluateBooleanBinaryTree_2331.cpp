/*
You are given the root of a full binary tree with the following properties:

    Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
    Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.

The evaluation of a node is as follows:

    If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
    Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.

Return the boolean result of evaluating the root node.

A full binary tree is a binary tree where each node has either 0 or 2 children.

A leaf node is a node that has zero children.*/

#include "../utils.h"
#include "gtest/gtest.h"

class Solution2331 : public ::testing::Test {
public:
    static bool evaluateTree(TreeNode *root) {
        if (root->val == 0)
            return false;
        else if (root->val == 1)
            return true;
        else if (root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        else
            return evaluateTree(root->left) && evaluateTree(root->right);
    }
};


TEST(Solution2331, T1) {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(0);
    TreeNode t3 = TreeNode(3, &t1, &t2);
    TreeNode t4 = TreeNode(1);
    TreeNode t5 = TreeNode(2, &t4, &t3);
    ASSERT_TRUE(Solution2331::evaluateTree(&t5));
}

TEST(Solution2331, T2) {
    TreeNode t1 = TreeNode(0);
    ASSERT_FALSE(Solution2331::evaluateTree(&t1));
}