/*
 You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.



Example 1:

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Example 2:

Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.



Constraints:

    1 <= m, n <= 105
    1 <= m * n <= 105
    The number of nodes in the list is in the range [1, m * n].
    0 <= Node.val <= 1000


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2326 : public ::testing::Test {
public:
    static vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        int dx = 1, dy = 0;
        int x = 0, y = 0, tmp1, tmp2;
        vector<vector<int>> res(m, vector<int>(n, -1));
        while (head) {
            res[y][x] = head->val;
            head = head->next;
            tmp1 = x + dx;
            tmp2 = y + dy;
            if (tmp1 == n || tmp1 == -1 || tmp2 == m || tmp2 == -1 ||
                res[tmp2][tmp1] != -1) {
                if (dy) {
                    dx = -dy;
                    dy = 0;
                } else {
                    dy = dx;
                    dx = 0;
                }
            }
            x += dx;
            y += dy;
        }
        return res;
    }
};

TEST(Solution2326, T1) {
    ListNode *head = ListNode::vectorToList({3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0});
    int m = 3;
    int n = 5;
    vector<vector<int>> expected = {{3, 0, 2,  6,  8},
                                    {5, 0, -1, -1, 1},
                                    {5, 2, 4,  9,  7}};
    ASSERT_TRUE(expected == Solution2326::spiralMatrix(m, n, head));
}

TEST(Solution2326, T2) {
    ListNode *head = ListNode::vectorToList({0, 1, 2});
    int m = 1;
    int n = 4;
    vector<vector<int>> expected = {{0, 1, 2, -1}};
    ASSERT_TRUE(expected == Solution2326::spiralMatrix(m, n, head));
}