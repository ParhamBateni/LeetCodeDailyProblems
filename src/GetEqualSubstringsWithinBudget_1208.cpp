/*
You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
 */

#include "../utils.h"
#include "gtest/gtest.h"
class Solution1208 : public ::testing::Test {
public:
    static int equalSubstring(string s, string t, int maxCost) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = s.size();
        int dist =0;
        int start = 0;
        int mxLength = -1;
        for (int end=0;end<n;end++){
            dist+=abs(s[end]-t[end]);
            while (dist>maxCost){
                dist -= abs(s[start]-t[start]);
                start++;
            }
            mxLength = max(mxLength,end-start);
        }
        return mxLength+1;
    }
};


TEST(Solution1208, T1) {
    string s = "abcd";
    string t = "bcdf";
    int maxCost =  3;
    ASSERT_EQ(3, Solution1208::equalSubstring(s,t,maxCost));
}

TEST(Solution1208, T2) {
    string s = "abcd";
    string t = "cdef";
    int maxCost =  3;
    ASSERT_EQ(1, Solution1208::equalSubstring(s,t,maxCost));
}
TEST(Solution1208, T3) {
    string s = "abcd";
    string t = "acde";
    int maxCost =  0;
    ASSERT_EQ(1, Solution1208::equalSubstring(s,t,maxCost));
}