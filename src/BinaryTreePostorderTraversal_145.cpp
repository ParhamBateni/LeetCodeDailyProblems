/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.



Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]



Constraints:

    The number of the nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution145 : public ::testing::Test {
public:
    static vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> order;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});
        pair<TreeNode *, int> tmp;
        while (st.size()) {
            tmp = st.top();
            if (tmp.second == 0) {
                st.top().second += 1;
                if (tmp.first->left != nullptr)
                    st.push({tmp.first->left, 0});
            } else if (tmp.second == 1) {
                st.top().second += 1;
                if (tmp.first->right != nullptr)
                    st.push({tmp.first->right, 0});
            } else {
                order.push_back(tmp.first->val);
                st.pop();
            }
        }
        return order;
    }
};

TEST(Solution145, T1) {
    TreeNode *root = TreeNode::vectorToTree({1, NULL, 2, 3});
    vector<int> expected{3, 2, 1};
    vector<int> output = Solution145::postorderTraversal(root);
    ASSERT_TRUE(expected == Solution145::postorderTraversal(root));
}

TEST(Solution145, T2) {
    TreeNode *root = TreeNode::vectorToTree({});
    vector<int> expected{};
    ASSERT_TRUE(expected == Solution145::postorderTraversal(root));
}

TEST(Solution145, T3) {
    TreeNode *root = TreeNode::vectorToTree({1});
    vector<int> expected{1};
    ASSERT_TRUE(expected == Solution145::postorderTraversal(root));
}