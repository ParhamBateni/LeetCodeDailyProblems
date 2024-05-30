/*
 An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

    'A': Absent.
    'L': Late.
    'P': Present.

Any student is eligible for an attendance award if they meet both of the following criteria:

    The student was absent ('A') for strictly fewer than 2 days total.
    The student was never late ('L') for 3 or more consecutive days.

Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution552 : public ::testing::Test {
public:
    static int checkRecord(int n) {
        int mem[2][2][3];
        int modulo = 1e9 + 7;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                mem[1][i][j] = 1;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            mem[0][1][2] = mem[1][1][0];
            mem[0][1][1] = (mem[1][1][2] + mem[1][1][0]) % modulo;
            mem[0][1][0] = (mem[1][1][0] + mem[1][1][1]) % modulo;
            mem[0][0][2] = (mem[1][1][0] + mem[1][0][0]) % modulo;
            mem[0][0][1] =
                    (mem[1][1][0] + (mem[1][0][2] + mem[1][0][0]) % modulo) %
                    modulo;
            mem[0][0][0] =
                    (mem[1][0][0] + (mem[1][1][0] + mem[1][0][1]) % modulo) %
                    modulo;

            mem[1][1][2] = mem[0][1][2];
            mem[1][1][1] = mem[0][1][1];
            mem[1][1][0] = mem[0][1][0];
            mem[1][0][2] = mem[0][0][2];
            mem[1][0][1] = mem[0][0][1];
            mem[1][0][0] = mem[0][0][0];
        }
        return mem[0][0][0];
    }
};

TEST(Solution552, T1) {
    ASSERT_EQ(8, Solution552::checkRecord(2));
}

TEST(Solution552, T2) {
    ASSERT_EQ(3, Solution552::checkRecord(1));
}

TEST(Solution552, T3) {
    ASSERT_EQ(183236316, Solution552::checkRecord(10101));
}