/*
 Given a string s which consists of lowercase or uppercase letters, return the length of the longest
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome. */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution409 : public ::testing::Test {
public:
    static int longestPalindrome(string s) {
        int counts[52];
        int cnt= 0;
        for (char c: s){
            if (c>='a') counts[c-'a'+26]+=1;
            else counts[c-'A']+=1;
        }
        bool canBeOdd = false;
        for (int i=0;i<52;i++){
            cnt+= counts[i]/2 * 2;
            if (counts[i]%2==1) canBeOdd = true;
        }
        return canBeOdd? cnt+1:cnt;
    }
};

TEST(Solution409, T1) {
    ASSERT_EQ(7,Solution409::longestPalindrome("abccccdd"));
}

TEST(Solution409, T2) {
    ASSERT_EQ(1,Solution409::longestPalindrome("a"));
}