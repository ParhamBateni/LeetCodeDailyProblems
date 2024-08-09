/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.



Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Example 2:

Input: grid = [[8]]
Output: 0



Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 10
    0 <= grid[i][j] <= 15
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution840 : public ::testing::Test {
public:
    static int numMagicSquaresInside(vector<vector<int>> &grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = grid.size(), m = grid[0].size();
        int tmp, s, s1, s2;
        bool found;
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                found = true;
                set<int> seen;
                s1 = 0, s2 = 0;
                for (int k = 0; k < 3; k++) {
                    s = 0;
                    for (int l = 0; l < 3; l++) {
                        tmp = grid[i + k][j + l];
                        s += tmp;
                        if (l == 0)
                            s1 += tmp;
                        else if (l == 1)
                            s2 += tmp;
                        if (!seen.count(tmp) && tmp < 10 && tmp >= 1) {
                            seen.insert(tmp);
                        } else {
                            found = false;
                            break;
                        }
                    }
                    if (!found || s != 15) {
                        found = false;
                        break;
                    }
                }
                if (found &&
                    grid[i][j] + grid[i + 2][j + 2] ==
                    grid[i][j + 2] + grid[i + 2][j] &&
                    s1 == s2 && s1 == 15)
                    cnt++;
            }
        }
        return cnt;
    }
};

TEST(Solution840, T1) {
    vector<vector<int>> grid{{4, 3, 8, 4},
                             {9, 5, 1, 9},
                             {2, 7, 6, 2}};
    int expected = 1;
    ASSERT_EQ(expected, Solution840::numMagicSquaresInside(grid));
}

TEST(Solution840, T2) {
    vector<vector<int>> grid{{8}};
    int expected = 0;
    ASSERT_EQ(expected, Solution840::numMagicSquaresInside(grid));
}
