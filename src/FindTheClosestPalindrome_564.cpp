/*
 Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.



Example 1:

Input: n = "123"
Output: "121"

Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.



Constraints:

    1 <= n.length <= 18
    n consists of only digits.
    n does not have leading zeros.
    n is representing an integer in the range [1, 10^18 - 1].

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution564 : public ::testing::Test {
public:
    static string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1) {
            return to_string(stoi(n) - 1);
        }

        vector<long long> candidates;
        candidates.push_back(pow(10, len - 1) - 1);
        candidates.push_back(pow(10, len) + 1);
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string candidate = p + string(p.rbegin() + (len % 2), p.rend());
            candidates.push_back(stoll(candidate));
        }
        long long num = stoll(n);

        long long closest = -1;

        for (long long cand: candidates) {
            if (cand == num) continue;
            if (closest == -1 ||
                abs(cand - num) < abs(closest - num) ||
                (abs(cand - num) == abs(closest - num) && cand < closest)) {
                closest = cand;
            }
        }

        return to_string(closest);
    }
};

TEST(Solution564, T1) {
    string n = "123";
    string expected = "121";
    ASSERT_TRUE(expected == Solution564::nearestPalindromic(n));
}

TEST(Solution564, T2) {
    string n = "1";
    string expected = "0";
    ASSERT_TRUE(expected == Solution564::nearestPalindromic(n));
}
