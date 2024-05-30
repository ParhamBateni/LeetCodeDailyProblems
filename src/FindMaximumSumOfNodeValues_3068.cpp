/*
There exists an undirected tree with n nodes numbered 0 to n - 1. You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

    Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
        nums[u] = nums[u] XOR k
        nums[v] = nums[v] XOR k

Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times
 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution3068 : public ::testing::Test {
public:
    static long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
        int n = nums.size();
        long long dp[20001][2] = {0};
        dp[n][0] = 0, dp[n][1] = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            long long x = nums[i];
            for (int c = 0; c <= 1; c++)
                dp[i][c] = max(x + dp[i + 1][c], (x ^ k) + dp[i + 1][!c]);
        }
        return dp[0][0];
    }
};


TEST(Solution3068, T1) {
    vector<int> nums{1, 2, 1};
    int k = 3;
    vector<vector<int>> edges{vector{0, 1}, vector{0, 2}};
    ASSERT_EQ(6, Solution3068::maximumValueSum(nums, k, edges));
}

TEST(Solution3068, T2) {
    vector<int> nums{2, 3};
    int k = 7;
    vector<vector<int>> edges{vector{0, 1}};
    ASSERT_EQ(9, Solution3068::maximumValueSum(nums, k, edges));
}

TEST(Solution3068, T3) {
    vector<int> nums{7, 7, 7, 7, 7, 7};
    int k = 3;
    vector<vector<int>> edges{vector{0, 1}, vector{0, 2}, vector{0, 3}, vector{0, 4}, vector{0, 5}};
    ASSERT_EQ(42., Solution3068::maximumValueSum(nums, k, edges));
}