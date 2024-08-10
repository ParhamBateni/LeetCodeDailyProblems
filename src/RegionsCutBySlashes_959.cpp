/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.



Example 1:

Input: grid = [" /","/ "]
Output: 2

Example 2:

Input: grid = [" /","  "]
Output: 1

Example 3:

Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.



Constraints:

    n == grid.length == grid[i].length
    1 <= n <= 30
    grid[i][j] is either '/', '\', or ' '.

 */
#include "../utils.h"
#include "gtest/gtest.h"

//3x3 blocks for each character ' ', '/' and '\\' respectively
vector<vector<int>> emp = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};
vector<vector<int>> sb = {{0, 0, 1},
                          {0, 1, 0},
                          {1, 0, 0}};
vector<vector<int>> cb = {{1, 0, 0},
                          {0, 1, 0},
                          {0, 0, 1}};
//4 directions for dfs
vector<int> x = {1, 0, -1, 0};
vector<int> y = {0, 1, 0, -1};
//To Store our binary matrix
vector<vector<int>> mat;

class Solution959 : public ::testing::Test {
public:
    //Normal DFS to find number of islands
    static void dfs(int i, int j) {
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] == 1) return;
        mat[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int newi = i + x[k];
            int newj = j + y[k];
            dfs(newi, newj);
        }
    }

    // To fill the our binary matrix with the blocks we made
    static void filling(vector<vector<int>> &arr, int i) {
        for (int k = 0; k < 3; k++) {
            mat[i].push_back(arr[0][k]);
            mat[i + 1].push_back(arr[1][k]);
            mat[i + 2].push_back(arr[2][k]);
        }
    }

    static int regionsBySlashes(vector<string> &grid) {
        mat.resize(grid.size() * 3);
        int ind = 0;
        //Fill with appropriate blocks 
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == ' ') filling(emp, ind);
                else if (grid[i][j] == '/') filling(sb, ind);
                else filling(cb, ind);
            }
            ind += 3;
        }
        //Number of Islands
        int ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

TEST(Solution959, T1) {
    vector<string> grid{" /", "/ "};
    int expected = 2;
    ASSERT_EQ(expected, Solution959::regionsBySlashes(grid));
}

TEST(Solution959, T2) {
    vector<string> grid{" /", "  "};
    int expected = 1;
    ASSERT_EQ(expected, Solution959::regionsBySlashes(grid));
}

TEST(Solution959, T3) {
    vector<string> grid{"/\\", "\\/"};
    int expected = 5;
    ASSERT_EQ(expected, Solution959::regionsBySlashes(grid));
}