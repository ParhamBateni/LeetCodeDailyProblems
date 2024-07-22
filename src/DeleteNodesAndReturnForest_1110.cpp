/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.



Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]



Constraints:

    The number of nodes in the given tree is at most 1000.
    Each node has a distinct value between 1 and 1000.
    to_delete.length <= 1000
    to_delete contains distinct values between 1 and 1000.

 */
#include "../utils.h"
#include "gtest/gtest.h"
bool t = true;
class Solution1110 : public ::testing::Test {
private:
    static int findHeight(TreeNode* root, int val) {
        if (!root)
            return -2;
        if (root->val == val)
            return 0;
        return max(findHeight(root->right, val), findHeight(root->left, val)) +
               1;
    }

public:
    static vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root)
            return {};
        vector<TreeNode*> res;
        bool p = false;
        if (t) {
            res.push_back(root);
            p =true;
        }
        t = false;
        TreeNode* right= root->right;
        TreeNode* left = root->left;
        for (int i = 0; i < to_delete.size(); i++) {
            if (to_delete[i] == root->val) {
                to_delete.erase(to_delete.begin() + i);
                if (p)res.pop_back();
                t = true;
                break;
            }
        }
        bool tmp = t;
        vector<TreeNode*> rightNodes = delNodes(right, to_delete);
        if (t) root->right = nullptr;
        t = tmp;
        vector<TreeNode*> leftNodes = delNodes(left, to_delete);
        if (t) root->left = nullptr;
        t = tmp;
        res.insert(res.end(), rightNodes.begin(), rightNodes.end());
        res.insert(res.end(), leftNodes.begin(), leftNodes.end());
        return res;
    }
};

TEST(Solution1110, T1) {
    t = true;
    TreeNode* root = TreeNode::vectorToTree({1,2,3,4,5,6,7});
    vector<int> to_delete {3,5};
    vector<vector<int>> expected = {{1,2,NULL,4},{7},{6}};
    vector<TreeNode*> res = Solution1110::delNodes(root,to_delete);
    ASSERT_EQ(res.size(),expected.size());
    for (int i =0;i<res.size();i++){
        ASSERT_TRUE(expected[i]==TreeNode::treeToVector(res[i]));
    }
}
TEST(Solution1110, T2) {
    t= true;
    TreeNode* root = TreeNode::vectorToTree({1,2,4,NULL,3});
    vector<int> to_delete {3};
    vector<vector<int>> expected = {{1,2,4}};
    vector<TreeNode*> res = Solution1110::delNodes(root,to_delete);
    ASSERT_EQ(res.size(),expected.size());
    for (int i =0;i<res.size();i++){
        ASSERT_TRUE(expected[i]==TreeNode::treeToVector(res[i]));
    }
}
