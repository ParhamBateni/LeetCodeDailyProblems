/*
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.



Example 1:

Input: s = "(abcd)"
Output: "dcba"

Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.



Constraints:

    1 <= s.length <= 2000
    s only contains lower case English characters and parentheses.
    It is guaranteed that all parentheses are balanced.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1190 : public ::testing::Test {
public:
    static string reverseParentheses(string s, int start = 0, int end = 2001) {
        end = min(end, (int) s.size());
        string res, tmp;
        int c = 0, p = 2001;
        for (int i = start; i < end; i++) {
            if (s[i] == '(') {
                c++;
                p = min(i, p);
            } else if (s[i] == ')') {
                if (--c == 0) {
                    tmp = reverseParentheses(s, p + 1, i);
                    reverse(tmp.begin(), tmp.end());
                    res += tmp;
                    p = 2001;
                }
            } else if (c == 0) {
                res += s[i];
            }
        }
        return res;
    }
};

TEST(Solution1190, T1) {
    string s = "(abcd)";
    string expected = "dcba";
    ASSERT_TRUE(expected == Solution1190::reverseParentheses(s));
}

TEST(Solution1190, T2) {
    string s = "(u(love)i)";
    string expected = "iloveu";
    ASSERT_TRUE(expected == Solution1190::reverseParentheses(s));
}

TEST(Solution1190, T3) {
    string s = "(ed(et(oc))el)";
    string expected = "leetcode";
    ASSERT_TRUE(expected == Solution1190::reverseParentheses(s));
}
