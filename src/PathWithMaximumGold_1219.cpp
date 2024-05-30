/*
 * There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

    Every worker in the paid group must be paid at least their minimum wage expectation.
    In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.

Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1219 : public ::testing::Test {
private:
    static int dfs(vector<vector<int>> &grid, vector<vector<bool>> &marked, int i, int j) {
        if (grid[i][j] == 0 || marked[i][j]) return 0;
        marked[i][j] = true;
        int mx = 0;
        if (i > 0 && !marked[i - 1][j]) {
            mx = max(dfs(grid, marked, i - 1, j), mx);
            marked[i - 1][j] = false;
        }
        if (i < grid.size() - 1 && !marked[i + 1][j]) {
            mx = max(dfs(grid, marked, i + 1, j), mx);
            marked[i + 1][j] = false;
        }

        if (j > 0 && !marked[i][j - 1]) {
            mx = max(dfs(grid, marked, i, j - 1), mx);
            marked[i][j - 1] = false;
        }
        if (j < grid[0].size() - 1 && !marked[i][j + 1]) {
            mx = max(dfs(grid, marked, i, j + 1), mx);
            marked[i][j + 1] = false;
        }
        return mx + grid[i][j];
    }

public:
    static int getMaximumGold(vector<vector<int>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                vector<vector<bool>> marked(grid.size(), vector<bool>(grid[0].size()));
                res = max(res, dfs(grid, marked, i, j));
            }
        }
        return res;
    }
};

TEST(Solution1219, T1) {
    vector<vector<int>> v = vector{vector{0, 6, 0}, vector{5, 8, 7}, vector{0, 9, 0}};
    ASSERT_EQ(24, Solution1219::getMaximumGold(v));
}

TEST(Solution1219, T2) {
    vector<vector<int>> v = vector{vector{1, 0, 7}, vector{2, 0, 6}, vector{3, 4, 5}, vector{0, 3, 0},
                                   vector{9, 0, 20}};
    ASSERT_EQ(28, Solution1219::getMaximumGold(v));
}