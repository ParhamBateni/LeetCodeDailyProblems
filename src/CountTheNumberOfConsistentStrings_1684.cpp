/*
 You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.



Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.



Constraints:

    1 <= words.length <= 104
    1 <= allowed.length <= 26
    1 <= words[i].length <= 10
    The characters in allowed are distinct.
    words[i] and allowed contain only lowercase English letters.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1684 : public ::testing::Test {
public:
    static int countConsistentStrings(string allowed, vector<string> &words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int res = 0;
        set<char> allowedSet;
        for (char c: allowed) {
            allowedSet.insert(c);
        }
        bool isAllowed;
        for (string s: words) {
            isAllowed = true;
            for (char c: s) {
                if (!allowedSet.count(c)) {
                    isAllowed = false;
                    break;
                }
            }
            if (isAllowed)
                res++;
        }
        return res;
    }
};

TEST(Solution1684, T1) {
    string allowed = "ab";
    vector<string> words{"ad", "bd", "aaab", "baa", "badab"};
    int expected = 2;
    ASSERT_TRUE(expected == Solution1684::countConsistentStrings(allowed, words));
}

TEST(Solution1684, T2) {
    string allowed = "abc";
    vector<string> words{"a", "b", "c", "ab", "ac", "bc", "abc"};
    int expected = 7;
    ASSERT_TRUE(expected == Solution1684::countConsistentStrings(allowed, words));
}

TEST(Solution1684, T3) {
    string allowed = "cad";
    vector<string> words{"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
    int expected = 4;
    ASSERT_TRUE(expected == Solution1684::countConsistentStrings(allowed, words));
}