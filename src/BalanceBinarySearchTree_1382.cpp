/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.



Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]



Constraints:

    The number of nodes in the tree is in the range [1, 104].
    1 <= Node.val <= 105


 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1382 : public ::testing::Test {
public:
    static TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedElements;
        inOrderTraversal(root, sortedElements);
        return buildBalancedBST(sortedElements, 0, sortedElements.size() - 1);
    }

private:
    static void inOrderTraversal(TreeNode* node, vector<int>& sortedElements) {
        if (!node) {
            return;
        }
        inOrderTraversal(node->left, sortedElements);
        sortedElements.push_back(node->val);
        inOrderTraversal(node->right, sortedElements);
    }

    static TreeNode* buildBalancedBST(const vector<int>& elements, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(elements[mid]);
        node->left = buildBalancedBST(elements, start, mid - 1);
        node->right = buildBalancedBST(elements, mid + 1, end);
        return node;
    }
};

TEST(Solution1382,T1){
    TreeNode t1 = TreeNode(4);
    TreeNode t2 = TreeNode(3,nullptr,&t1);
    TreeNode t3 = TreeNode(2, nullptr, &t2);
    TreeNode t4 = TreeNode(1,nullptr,&t3);
    TreeNode* root = Solution1382::balanceBST(&t4);
    ASSERT_TRUE(root->val==2 && root->left->val==1 && root->right->val==3 && root->right->right->val==4);
}
