/*
 * There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

    Every worker in the paid group must be paid at least their minimum wage expectation.
    In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.

Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution861 : public ::testing::Test {
private:
    static void flipRow(vector<vector<int>> &grid, int row) {
        for (int i = 0; i < grid[0].size(); i++) {
            grid[row][i] ^= 1;
        }
    }

    static void flipColumn(vector<vector<int>> &grid, int col) {
        for (int i = 0; i < grid.size(); i++) {
            grid[i][col] ^= 1;
        }
    }

    static int computeScore(vector<vector<int>> &grid) {
        int score = 0;
        int s;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            s = 0;
            for (int j = 0; j < m; j++) {
                s += grid[i][j] << (m - j - 1);
            }
            score += s;
        }
        return score;
    }

public:
    static int matrixScore(vector<vector<int>> &grid) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                flipRow(grid, i);
            }
        }
        int s;
        for (int i = 0; i < m; i++) {
            s = 0;
            for (int j = 0; j < n; j++) {
                s += grid[j][i];
            }
            if (s <= n / 2) flipColumn(grid, i);
        }
        return computeScore(grid);
    }
};

TEST(Solution861, T1) {
    vector<vector<int>> v = vector{vector{0, 0, 1, 1}, vector{1, 0, 1, 0}, vector{1, 1, 0, 0}};
    ASSERT_EQ(39, Solution861::matrixScore(v));
}

TEST(Solution861, T2) {
    vector<vector<int>> v;
    v.push_back(vector<int>{0});
    ASSERT_EQ(1, Solution861::matrixScore(v));
}