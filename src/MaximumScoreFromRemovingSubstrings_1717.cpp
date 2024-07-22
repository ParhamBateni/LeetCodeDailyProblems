/*
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

    Remove substring "ab" and gain x points.
        For example, when removing "ab" from "cabxbae" it becomes "cxbae".
    Remove substring "ba" and gain y points.
        For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.



Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20



Constraints:

    1 <= s.length <= 105
    1 <= x, y <= 104
    s consists of lowercase English letters.

 */
#include "../utils.h"
#include "gtest/gtest.h"


class Solution1717 : public ::testing::Test {
public:
    static int maximumGain(std::string s, int x, int y) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        string firstPattern, secondPattern;
        int highScore, lowScore;

        // Determine which pattern has the higher score
        if (x >= y) {
            firstPattern = "ab";
            secondPattern = "ba";
            highScore = x;
            lowScore = y;
        } else {
            firstPattern = "ba";
            secondPattern = "ab";
            highScore = y;
            lowScore = x;
        }

        int totalScore = 0;
        stack<char> stack;

        // First pass: remove the higher score pattern
        for (char c : s) {
            if (!stack.empty() && stack.top() == firstPattern[0] &&
                c == firstPattern[1]) {
                // If the current character and the stack's top form the pattern
                stack.pop(); // Remove the pattern
                totalScore += highScore;
            } else {
                stack.push(c);
            }
        }

        // Remaining characters are processed for the lower score pattern
        string remaining;
        while (!stack.empty()) {
            remaining += stack.top();
            stack.pop();
        }

        // Reverse the remaining string to restore order
        reverse(remaining.begin(), remaining.end());

        // Second pass: remove the lower score pattern
        for (char c : remaining) {
            if (!stack.empty() && stack.top() == secondPattern[0] &&
                c == secondPattern[1]) {
                stack.pop();
                totalScore += lowScore;
            } else {
                stack.push(c);
            }
        }

        return totalScore;
    }
};

TEST(Solution1717, T1) {
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    int expected  = 19;
    ASSERT_EQ(expected, Solution1717::maximumGain(s, x, y));
}

TEST(Solution1717, T2) {
    string s = "aabbaaxybbaabb";
    int x = 5;
    int y = 4;
    int expected  = 20;
    ASSERT_EQ(expected, Solution1717::maximumGain(s, x, y));
}
