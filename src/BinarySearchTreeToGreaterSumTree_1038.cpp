/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.



Example 1:

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]



Constraints:

    The number of nodes in the tree is in the range [1, 100].
    0 <= Node.val <= 100
    All the values in the tree are unique.

*/

#include "../utils.h"
#include "gtest/gtest.h"
int sum = 0;
class Solution1038 : public ::testing::Test {
private:

    static void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);  // Traverse the right subtree
            sum += root->val;  // Update the sum
            root->val = sum;  // Update the current node's value
            traverse(root->left);  // Traverse the left subtree
        }
    }

public:
    static TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};
