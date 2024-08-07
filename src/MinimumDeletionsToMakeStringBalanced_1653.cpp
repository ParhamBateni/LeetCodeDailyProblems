/*
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.



Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.



Constraints:

    1 <= s.length <= 105
    s[i] is 'a' or 'b'​​.


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1653 : public ::testing::Test {
public:
    static int minimumDeletions(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'b') {
                f[i] = f[i - 1];
                ++b;
            } else {
                f[i] = min(f[i - 1] + 1, b);
            }
        }
        return f[n];
    }
};

TEST(Solution1653, T1) {
    string s = "aababbab";
    int expected = 2;
    ASSERT_EQ(expected, Solution1653::minimumDeletions(s));
}

TEST(Solution1653, T2) {
    string s = "bbaaaaabb";
    int expected = 2;
    ASSERT_EQ(expected, Solution1653::minimumDeletions(s));
}
