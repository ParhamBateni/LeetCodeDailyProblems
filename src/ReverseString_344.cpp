/*
 Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution344 : public ::testing::Test {
public:
    static void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};

TEST(Solution344, T1) {
    vector<char> v{'h','e','l','l','o'};
    vector<char> expected{'o','l','l','e','h'};
    Solution344::reverseString(v);
    ASSERT_TRUE(expected == v);
}
TEST(Solution344, T2) {
    vector<char> v{'H','a','n','n','a','h'};
    vector<char> expected{'h','a','n','n','a','H'};
    Solution344::reverseString(v);
    ASSERT_TRUE(expected == v);
}