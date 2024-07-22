/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.



Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.



Constraints:

    m == mat.length
    n == mat[i].length
    1 <= n, m <= 50
    1 <= matrix[i][j] <= 105.
    All elements in the matrix are distinct.


 */
#include "../utils.h"
#include "gtest/gtest.h"


class Solution1380 : public ::testing::Test {
public:
    static vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = matrix.size(), n = matrix[0].size(), tmp;
        int mxs[n];
        vector<int> res;
        for (int j = 0; j < n; j++) {
            mxs[j] = 0;
            for (int i = 0; i < m; i++) {
                mxs[j] = max(mxs[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            tmp = 1e6;
            for (int j = 0; j < n; j++) {
                tmp = min(tmp, matrix[i][j]);
            }
            for (int j = 0; j < n; j++) {
                if (mxs[j] == tmp)
                    res.push_back(mxs[j]);
            }
        }
        return res;
    }
};

TEST(Solution1380, T1) {
    vector<vector<int>> matrix{{3,  7,  8},
                               {9,  11, 13},
                               {15, 16, 17}};
    vector<int> expected = {15};
    ASSERT_TRUE(expected == Solution1380::luckyNumbers(matrix));
}

TEST(Solution1380, T2) {
    vector<vector<int>> matrix{{1,  10, 4,  2},
                               {9,  3,  8,  7},
                               {15, 16, 17, 12}};
    vector<int> expected = {12};
    ASSERT_TRUE(expected == Solution1380::luckyNumbers(matrix));
}


TEST(Solution1380, T3) {
    vector<vector<int>> matrix{{7, 8},
                               {1, 2}};
    vector<int> expected = {7};
    ASSERT_TRUE(expected == Solution1380::luckyNumbers(matrix));
}
