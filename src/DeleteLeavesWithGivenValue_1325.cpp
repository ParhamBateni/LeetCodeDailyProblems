/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).*/

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1325 : public ::testing::Test {
public:
    static TreeNode *removeLeafNodes(TreeNode *root, int target) {
        if (root == NULL) return NULL;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->val == target && root->right == NULL && root->left == NULL) return NULL;
        return root;
    }
};


TEST(Solution1325, T1) {
    TreeNode t1 = TreeNode(2);
    TreeNode t2 = TreeNode(4);
    TreeNode t3 = TreeNode(3, &t1, &t2);
    TreeNode t4 = TreeNode(2);
    TreeNode t5 = TreeNode(2, &t4, nullptr);
    TreeNode t6 = TreeNode(2, &t5, nullptr);
    TreeNode t7 = TreeNode(1, &t6, &t3);
    TreeNode *res = Solution1325::removeLeafNodes(&t7, 2);
    ASSERT_EQ(res->val, 1);
    ASSERT_EQ(res->right->val, 3);
    ASSERT_EQ(res->right->right->val, 4);
}

TEST(Solution1325, T2) {
    TreeNode t1 = TreeNode(3);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3, &t1, &t2);
    TreeNode t4 = TreeNode(3);
    TreeNode t5 = TreeNode(1, &t3, &t4);
    TreeNode *res = Solution1325::removeLeafNodes(&t5, 3);
    ASSERT_EQ(res->val, 1);
    ASSERT_EQ(res->left->val, 3);
    ASSERT_EQ(res->left->right->val, 2);
}

TEST(Solution1325, T3) {
    TreeNode t1 = TreeNode(2);
    TreeNode t2 = TreeNode(2, &t1, nullptr);
    TreeNode t3 = TreeNode(2, &t2, nullptr);
    TreeNode t4 = TreeNode(1, &t3, nullptr);
    TreeNode *res = Solution1325::removeLeafNodes(&t4, 2);
    ASSERT_EQ(res->val, 1);
}