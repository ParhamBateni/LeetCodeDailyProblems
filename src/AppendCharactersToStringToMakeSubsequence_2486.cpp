/*
 You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2486 : public ::testing::Test {
public:
    static int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int i=0,j=0;
        while (i<s.size()){
            if (s[i++]==t[j]) j++;
        }
        return t.size()-j;
    }
};

TEST(Solution2486, T1) {
    ASSERT_EQ(4,Solution2486::appendCharacters("coaching","coding"));
}

TEST(Solution2486, T2) {
    ASSERT_EQ(0,Solution2486::appendCharacters("abcde","a"));
}

TEST(Solution2486, T3) {
    ASSERT_EQ(5,Solution2486::appendCharacters("z","abcde"));
}