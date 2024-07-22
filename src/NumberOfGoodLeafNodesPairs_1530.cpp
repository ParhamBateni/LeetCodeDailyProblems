/*
You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.



Example 1:

Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.

Example 2:

Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.

Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].



Constraints:

    The number of nodes in the tree is in the range [1, 210].
    1 <= Node.val <= 100
    1 <= distance <= 10
 */
#include "../utils.h"
#include "gtest/gtest.h"


class Solution1530 : public ::testing::Test {
private:
    static vector<int> countPairsAndFindDistances(TreeNode *root, int distance) {
        if (root == nullptr)
            return vector<int>(distance + 1, 0);
        if (root->right == nullptr && root->left == nullptr) {
            vector<int> v(distance + 1, 0);
            v[1] = 1;
            return v;
        }
        vector<int> v_right, v_left, v_root(distance + 1);
        v_right = countPairsAndFindDistances(root->right, distance);
        v_left = countPairsAndFindDistances(root->left, distance);
        v_root[0] = v_left[0] + v_right[0];
        for (int i = 1; i < distance; i++) {
            v_root[i + 1] = v_right[i] + v_left[i];
            for (int d = 1; d <= distance - i; d++) {
                v_root[0] += v_left[i] * v_right[d];
            }
        }
        return v_root;
    }

public:
    static int countPairs(TreeNode *root, int distance) {
        return countPairsAndFindDistances(root, distance)[0];
    }
};

TEST(Solution1530, T1) {
    TreeNode *root = TreeNode::vectorToTree({1, 2, 3, NULL, 4});
    int distance = 3;
    int expected = 1;
    ASSERT_EQ(expected, Solution1530::countPairs(root, distance));
}


TEST(Solution1530, T2) {
    TreeNode *root = TreeNode::vectorToTree({1, 2, 3, 4, 5, 6, 7});
    int distance = 3;
    int expected = 2;
    ASSERT_EQ(expected, Solution1530::countPairs(root, distance));
}


TEST(Solution1530, T3) {
    TreeNode *root = TreeNode::vectorToTree({7, 1, 4, 6, NULL, 5, 3, NULL, NULL, NULL, NULL, NULL, 2});
    int distance = 3;
    int expected = 1;
    ASSERT_EQ(expected, Solution1530::countPairs(root, distance));
}
