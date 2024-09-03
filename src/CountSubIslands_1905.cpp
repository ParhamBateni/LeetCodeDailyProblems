/*
 You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.



Example 1:

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:

Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.



Constraints:

    m == grid1.length == grid2.length
    n == grid1[i].length == grid2[i].length
    1 <= m, n <= 500
    grid1[i][j] and grid2[i][j] are either 0 or 1.


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1905 : public ::testing::Test {
private:
    static bool isInside(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    static int countSubIslands(vector<vector<int>> &grid1,
                               vector<vector<int>> &grid2) {
        int m = grid1.size(), n = grid1[0].size();
        set<pair<int, int>> seen;
        int x, y;
        bool isSubset;
        int cnt = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] && grid1[i][j] && !seen.count({i, j})) {
                    isSubset = true;
                    st.push({i, j});
                    while (st.size()) {
                        x = st.top().first;
                        y = st.top().second;
                        st.pop();
                        seen.insert({x, y});
                        for (int k = -1; k <= 1; k++) {
                            for (int l = -1; l <= 1; l++) {
                                if (abs(k) + abs(l) <= 1 &&
                                    isInside(x + k, y + l, m, n) &&
                                    grid2[x + k][y + l] &&
                                    !seen.count({x + k, y + l})) {
                                    if (!grid1[x + k][y + l])
                                        isSubset = false;
                                    st.push({x + k, y + l});
                                }
                            }
                        }
                    }
                    if (isSubset)
                        cnt += 1;
                }
            }
        }
        return cnt;
    }
};

TEST(Solution1905, T1) {
    vector<vector<int>> grid1{{1, 1, 1, 0, 0},
                              {0, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0},
                              {1, 1, 0, 1, 1}};
    vector<vector<int>> grid2{{1, 1, 1, 0, 0},
                              {0, 0, 1, 1, 1},
                              {0, 1, 0, 0, 0},
                              {1, 0, 1, 1, 0},
                              {0, 1, 0, 1, 0}};
    int expected = 3;
    ASSERT_TRUE(expected == Solution1905::countSubIslands(grid1, grid2));
}

TEST(Solution1905, T2) {
    vector<vector<int>> grid1{{1, 0, 1, 0, 1},
                              {1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1},
                              {1, 0, 1, 0, 1}};
    vector<vector<int>> grid2{{0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1},
                              {0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0},
                              {1, 0, 0, 0, 1}};
    int expected = 2;
    ASSERT_TRUE(expected == Solution1905::countSubIslands(grid1, grid2));
}
