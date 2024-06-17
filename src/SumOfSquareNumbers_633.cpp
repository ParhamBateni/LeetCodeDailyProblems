/*
 Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.


Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: c = 3
Output: false



Constraints:

    0 <= c <= 231 - 1
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution633 : public ::testing::Test {
public:
    static bool judgeSquareSum(int c) {
        double f;
        for (int i = 0; i <= sqrt(c / 2); i++) {
            f = sqrt(c-i*i);
            if (((int)f) == f)
                return true;
        }
        return false;
    }
};

TEST(Solution633, T1) {
    int c = 5;
    int expected  = true;
    ASSERT_EQ(expected,Solution633::judgeSquareSum(c));
}
TEST(Solution633, T2) {
    int c = 3;
    int expected  = false;
    ASSERT_EQ(expected,Solution633::judgeSquareSum(c));
}
