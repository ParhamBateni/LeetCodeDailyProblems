/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.



Example 1:

Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Example 2:

Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]



Constraints:

    1 <= rows, cols <= 100
    0 <= rStart < rows
    0 <= cStart < cols

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution885 : public ::testing::Test {
public:
    static vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                               int cStart) {
        vector<vector<int>> coordinates;
        int i = rStart, j = cStart, d = 1, c = 1;
        int mxI = -1, mxJ = -1, mnI = INT_MAX, mnJ = INT_MAX;
        while (mxI < rows || mxJ < cols || mnI >= 0 || mnJ >= 0) {
            if (i < rows && i >= 0) {
                for (int jj = j; jj * d < (j + c * d) * d; jj += d) {
                    if (jj < cols && jj >= 0)
                        coordinates.push_back({i, jj});
                }
            }
            j += c * d;
            if (j < cols && j >= 0) {
                for (int ii = i; ii * d < (i + c * d) * d; ii += d) {
                    if (ii < rows && ii >= 0)
                        coordinates.push_back({ii, j});
                }
            }
            i += c * d;
            c++;
            d *= -1;
            mxI = max(i, mxI);
            mxJ = max(j, mxJ);
            mnI = min(i, mnI);
            mnJ = min(j, mnJ);
        }
        return coordinates;
    }
};

TEST(Solution885, T1) {
    int rows = 1, cols = 4, rStart = 0, cStart = 0;
    vector<vector<int>> expected{{0, 0},
                                 {0, 1},
                                 {0, 2},
                                 {0, 3}};
    ASSERT_TRUE(expected == Solution885::spiralMatrixIII(rows, cols, rStart, cStart));
}

TEST(Solution885, T2) {
    int rows = 5, cols = 6, rStart = 1, cStart = 4;
    vector<vector<int>> expected{{1, 4},
                                 {1, 5},
                                 {2, 5},
                                 {2, 4},
                                 {2, 3},
                                 {1, 3},
                                 {0, 3},
                                 {0, 4},
                                 {0, 5},
                                 {3, 5},
                                 {3, 4},
                                 {3, 3},
                                 {3, 2},
                                 {2, 2},
                                 {1, 2},
                                 {0, 2},
                                 {4, 5},
                                 {4, 4},
                                 {4, 3},
                                 {4, 2},
                                 {4, 1},
                                 {3, 1},
                                 {2, 1},
                                 {1, 1},
                                 {0, 1},
                                 {4, 0},
                                 {3, 0},
                                 {2, 0},
                                 {1, 0},
                                 {0, 0}};
    ASSERT_TRUE(expected == Solution885::spiralMatrixIII(rows, cols, rStart, cStart));
}