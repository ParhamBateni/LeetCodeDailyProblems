/*
 You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

 

Example 1:

Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]
Explanation: The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.

Example 2:

Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]
Explanation: The constructed 2D array should contain 1 row and 3 columns.
Put all three elements in original into the first row of the constructed 2D array.

Example 3:

Input: original = [1,2], m = 1, n = 1
Output: []
Explanation: There are 2 elements in original.
It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.

 

Constraints:

    1 <= original.length <= 5 * 104
    1 <= original[i] <= 105
    1 <= m, n <= 4 * 104


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2022 : public ::testing::Test {
public:
    static vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        int c = 0;
        for (int num: original) {
            res[c / n][c % n] = num;
            c++;
        }
        return res;
    }
};

TEST(Solution2022, T1) {
    vector<int> original{1, 2, 3, 4};
    int m = 2;
    int n = 2;
    vector<vector<int>> expected{{1, 2},
                                 {3, 4}};
    ASSERT_TRUE(expected == Solution2022::construct2DArray(original, m, n));
}

TEST(Solution2022, T2) {
    vector<int> original{1, 2, 3};
    int m = 1;
    int n = 3;
    vector<vector<int>> expected{{1, 2, 3}};
    ASSERT_TRUE(expected == Solution2022::construct2DArray(original, m, n));
}

TEST(Solution2022, T3) {
    vector<int> original{1, 2};
    int m = 1;
    int n = 1;
    vector<vector<int>> expected{};
    ASSERT_TRUE(expected == Solution2022::construct2DArray(original, m, n));
}