/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

    'L' means to go from a node to its left child node.
    'R' means to go from a node to its right child node.
    'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.



Example 1:

Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

Example 2:

Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.



Constraints:

    The number of nodes in the tree is n.
    2 <= n <= 105
    1 <= Node.val <= n
    All the values in the tree are unique.
    1 <= startValue, destValue <= n
    startValue != destValue


 */
#include "../utils.h"
#include "gtest/gtest.h"


class Solution2096 : public ::testing::Test {
private:
    static bool findPath(TreeNode *root, int val, string &path) {
        if (!root)
            return false; // If the current node is null, return false

        // If the current node is the target value, return true
        if (root->val == val)
            return true;

        // Try to find the value in the left subtree
        path.push_back('L');
        if (findPath(root->left, val, path))
            return true;
        path.pop_back(); // Backtrack if not found

        // Try to find the value in the right subtree
        path.push_back('R');
        if (findPath(root->right, val, path))
            return true;
        path.pop_back(); // Backtrack if not found

        return false; // Return false if the value is not found
    }

public:
    static string getDirections(TreeNode *root, int startValue, int destValue) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        string pathToStart, pathToDest;

        // Find paths from the root to startValue and destValue
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        int c = 0;

        // Find the point where the paths diverge
        while (c < min(pathToStart.size(), pathToDest.size()) &&
               pathToStart[c] == pathToDest[c])
            c++;

        // Move up from startValue to the common ancestor
        string direction(pathToStart.size() - c, 'U');

        // Move from the common ancestor to destValue
        direction.append(pathToDest.begin() + c, pathToDest.end());

        return direction;
    }
};

TEST(Solution2096, T1) {
    TreeNode *root = TreeNode::vectorToTree({5, 1, 2, 3, NULL, 6, 4});
    int startValue = 3, destValue = 6;
    string expected = "UURL";
    ASSERT_TRUE(expected == Solution2096::getDirections(root, startValue, destValue));
}
TEST(Solution2096, T2) {
    TreeNode *root = TreeNode::vectorToTree({2,1});
    int startValue = 2, destValue = 1;
    string expected = "L";
    ASSERT_TRUE(expected == Solution2096::getDirections(root, startValue, destValue));
}
