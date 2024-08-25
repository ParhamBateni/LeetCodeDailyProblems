/*
 There is a strange printer with the following two special properties:

    The printer can only print a sequence of the same character each time.
    At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.

Given a string s, return the minimum number of turns the printer needed to print it.

 

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

 

Constraints:

    1 <= s.length <= 100
    s consists of lowercase English letters.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution664 : public ::testing::Test {
public:
    static int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};

TEST(Solution664, T1) {
    string s = "aaabbb";
    int expected = 2;
    ASSERT_TRUE(expected == Solution664::strangePrinter(s));
}

TEST(Solution664, T2) {
    string s = "aba";
    int expected = 2;
    ASSERT_TRUE(expected == Solution664::strangePrinter(s));
}