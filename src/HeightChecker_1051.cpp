/*
 You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1051 : public ::testing::Test {
public:
    static int heightChecker(vector<int>& heights) {
        vector<int> copyHeights = heights;
        sort(copyHeights.begin(),copyHeights.end());
        int c = 0;
        for (int i=0;i<heights.size();i++){
            if (heights[i]!=copyHeights[i])c++;
        }
        return c;
    }
};

TEST(Solution1051, T1) {
    vector<int> v {1,1,4,2,1,3};
    int expected = 3;
    ASSERT_EQ(expected,Solution1051::heightChecker(v));
}

TEST(Solution1051, T2) {
    vector<int> v {5,1,2,3,4};
    int expected = 5;
    ASSERT_EQ(expected,Solution1051::heightChecker(v));
}
TEST(Solution1051, T3) {
    vector<int> v {1,2,3,4,5};
    int expected = 0;
    ASSERT_EQ(expected,Solution1051::heightChecker(v));
}