/*
 Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.



Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.



Constraints:

    1 <= s.length <= 5 x 10^5
    s contains only lowercase English letters.


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1371 : public ::testing::Test {
public:
    static int findTheLongestSubstring(string s) {
        int n = s.size();
        int xors[n + 1];
        int tmp;
        for (int i = 1; i <= n; i++) {
            switch (s[i - 1]) {
                case 'a':
                    tmp = 16;
                    break;
                case 'e':
                    tmp = 8;
                    break;
                case 'i':
                    tmp = 4;
                    break;
                case 'o':
                    tmp = 2;
                    break;
                case 'u':
                    tmp = 1;
                    break;
                default:
                    tmp = 0;
            }
            xors[i] = xors[i - 1] ^ tmp;
        }
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j <= n - i; j++) {
                if (xors[j] == xors[j + i])
                    return i;
            }
        }
        return 0;
    }
};

TEST(Solution1371, T1) {
    string s = "eleetminicoworoep";
    int expected = 13;
    ASSERT_TRUE(expected == Solution1371::findTheLongestSubstring(s));
}

TEST(Solution1371, T2) {
    string s = "leetcodeisgreat";
    int expected = 5;
    ASSERT_TRUE(expected == Solution1371::findTheLongestSubstring(s));
}

TEST(Solution1371, T3) {
    string s = "bcbcbc";
    int expected = 6;
    ASSERT_TRUE(expected == Solution1371::findTheLongestSubstring(s));
}