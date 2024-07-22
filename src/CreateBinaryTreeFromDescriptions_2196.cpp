/*
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

    If isLefti == 1, then childi is the left child of parenti.
    If isLefti == 0, then childi is the right child of parenti.

Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.



Example 1:

Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:

Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.



Constraints:

    1 <= descriptions.length <= 104
    descriptions[i].length == 3
    1 <= parenti, childi <= 105
    0 <= isLefti <= 1
    The binary tree described by descriptions is valid.
 */
#include "../utils.h"
#include "gtest/gtest.h"


class Solution2196 : public ::testing::Test {
public:
    static TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        unordered_map<int, TreeNode*> nodes;
        set<int> s1, s2;
        TreeNode* p;
        TreeNode* c;
        for (const vector<int> d : descriptions) {
            if (nodes.count(d[0]))
                p = nodes[d[0]];
            else {
                p = new TreeNode(d[0]);
                nodes[d[0]] = p;
            }
            if (nodes.count(d[1]))
                c = nodes[d[1]];
            else {
                c = new TreeNode(d[1]);
                nodes[d[1]] = c;
            }
            if (d[2])
                p->left = c;
            else
                p->right = c;
            s1.insert(d[0]);
            s2.insert(d[1]);
        }
        for (auto& s : s1) {
            if (!s2.count(s))
                return nodes[s];
        }
        return nullptr;
    }
};

TEST(Solution2196, T1) {
    vector<vector<int>> descriptions {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    vector<int> expected {50,20,80,15,17,19};
    ASSERT_TRUE(expected == TreeNode::treeToVector(Solution2196::createBinaryTree(descriptions)));
}
TEST(Solution2196, T2) {
    vector<vector<int>> descriptions {{1,2,1},{2,3,0},{3,4,1}};
    vector<int> expected {1,2,NULL,NULL,3,4};
    ASSERT_TRUE(expected == TreeNode::treeToVector(Solution2196::createBinaryTree(descriptions)));
}