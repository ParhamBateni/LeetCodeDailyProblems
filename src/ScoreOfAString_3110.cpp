/*
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.*/

#include "../utils.h"
#include "gtest/gtest.h"

class Solution3110 : public ::testing::Test {
public:
    static int scoreOfString(string s) {
        int sum = 0;
        for (int i=0;i<s.size()-1;i++)sum+=abs(s[i]-s[i+1]);
        return sum;
    }
};


TEST(Solution3110, T1) {
    ASSERT_EQ(13, Solution3110::scoreOfString("hello"));
}

TEST(Solution3110, T2) {
    ASSERT_EQ(50, Solution3110::scoreOfString("zaz"));
}