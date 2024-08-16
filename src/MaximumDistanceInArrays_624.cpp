/*
 You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.



Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

Example 2:

Input: arrays = [[1],[1]]
Output: 0



Constraints:

    m == arrays.length
    2 <= m <= 105
    1 <= arrays[i].length <= 500
    -104 <= arrays[i][j] <= 104
    arrays[i] is sorted in ascending order.
    There will be at most 105 integers in all the arrays.


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution624 : public ::testing::Test {
public:
    static int maxDistance(vector<vector<int>> &arrays) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int mx1 = -1e4, mx2 = -1e4, tmp, mxDistance = -1;
        for (auto &v: arrays) {
            tmp = v[v.size() - 1];
            if (tmp > mx1) {
                mx2 = mx1;
                mx1 = tmp;
            } else if (tmp > mx2)
                mx2 = tmp;
        }
        for (auto &v: arrays) {
            if (v[v.size() - 1] == mx1)
                tmp = mx2;
            else
                tmp = mx1;
            mxDistance = max(mxDistance, tmp - v[0]);
        }
        return mxDistance;
    }
};

TEST(Solution624, T1) {
    vector<vector<int>> arrays{{1, 2, 3},
                               {4, 5},
                               {1, 2, 3}};
    int expected = 4;
    ASSERT_TRUE(expected == Solution624::maxDistance(arrays));
}

TEST(Solution624, T2) {
    vector<vector<int>> arrays{{1},
                               {1}};
    int expected = 0;
    ASSERT_TRUE(expected == Solution624::maxDistance(arrays));
}