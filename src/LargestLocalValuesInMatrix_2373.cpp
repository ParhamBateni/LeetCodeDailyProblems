/*
 You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
 */
#include "../utils.h"
#include "gtest/gtest.h"
class Solution2373:public::testing::Test{
public:
    static vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int mx = 0;
                for (int k = i; k < i+3; ++k) {
                    for (int l = j; l < j+3; ++l) {
                        mx = max(mx, grid[k][l]);
                    }
                }
                res[i][j] = mx;
            }
        }
        return res;
    }
};

TEST(Solution2373,T1){
    vector<vector<int>> v = vector{vector{9,9,8,1},vector{5,6,2,6},vector{8,2,6,4},vector{6,2,2,2}};
    vector<vector<int>> expected = vector{vector{9,9},vector{8,6}};
    ASSERT_TRUE(expected==Solution2373::largestLocal(v));
}
TEST(Solution2373,T2){
    vector<vector<int>> v = vector{vector{1,1,1,1,1},vector{1,1,1,1,1},vector{1,1,2,1,1},vector{1,1,1,1,1},vector{1,1,1,1,1}};
    vector<vector<int>> expected = vector{vector{2,2,2},vector{2,2,2},vector{2,2,2}};
    ASSERT_TRUE(expected==Solution2373::largestLocal(v));
}