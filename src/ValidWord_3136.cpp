/*
 You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
 */
#include "../utils.h"
#include "gtest/gtest.h"
class Solution3136:public::testing::Test{
public:
    static bool isValid(string word) {
        if (word.size()<3) return false;
        bool c1,c2;
        c1 = false;
        c2 = false;
        set<char> vowels = set<char>{'a','A','e','E','i','I','o','O','u','U'};
        for (char c: word){
            if (!(c>=48 && c<=57 || c>=65 && c<=90 || c>=97 && c<=122)){
                return false;
            }
            if (std::binary_search(vowels.begin(), vowels.end(),c)) c1 = true;
            else if(c>=65) c2 = true;
        }
        return c1&&c2;
    }
};

TEST(Solution3136,T1){
    ASSERT_TRUE(Solution3136::isValid("234Adas"));
}
TEST(Solution3136,T2){
    ASSERT_FALSE(Solution3136::isValid("b3"));
}
TEST(Solution3136,T3){
    ASSERT_FALSE(Solution3136::isValid("a3$e"));
}