/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
*/

#include "../utils.h"
#include "gtest/gtest.h"

vector<vector<string>> res;

class Solution131 : public ::testing::Test {
public:
    static bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }

    static vector<vector<string>> partition(string s, int start = 0, vector<string> cur = {}) {
        res = {};
        explore(s);
        return res;
    }

    static void explore(string s, int start = 0, vector<string> cur = {}) {
        int n = s.size();
        if (start >= n) res.push_back(cur);
        for (int i = start; i < n; i++) {
            string sb = s.substr(start, i - start + 1);
            if (isPalindrome(sb)) {
                cur.push_back(sb);
                explore(s, i + 1, cur);
                cur.pop_back();
            }
        }
    }
};


TEST(Solution131, T1) {
    ASSERT_EQ(2, Solution131::partition("aab").size());
}

TEST(Solution131, T2) {
    ASSERT_EQ(1, Solution131::partition("a").size());
}

TEST(Solution131, T3) {
    ASSERT_EQ(2, Solution131::partition("cdd").size());
}