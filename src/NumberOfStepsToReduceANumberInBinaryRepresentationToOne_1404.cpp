/*
 Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

    If the current number is even, you have to divide it by 2.

    If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
 */
#include "../utils.h"
#include "gtest/gtest.h"
class Solution1404:public::testing::Test{
public:
    static int numSteps(string s) {
        int cnt = 0, carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] == '0') {
                if (carry)
                    cnt++;
                else
                    carry = 0;
            } else {
                if (!carry)
                    cnt++;
                carry = 1;
            }
            cnt++;
        }
        return carry ? cnt + 1 : cnt;
    }
};

TEST(Solution1404,T1){
    string s = "1101";
    ASSERT_EQ(6,Solution1404::numSteps(s));
}
TEST(Solution1404,T2){
    string s = "10";
    ASSERT_EQ(1,Solution1404::numSteps(s));
}
TEST(Solution1404,T3){
    string s = "1";
    ASSERT_EQ(0,Solution1404::numSteps(s));
}