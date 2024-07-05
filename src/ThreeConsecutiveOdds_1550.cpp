/*
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.



Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.



Constraints:

    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000

 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1550 : public ::testing::Test {
public:
    static bool threeConsecutiveOdds(vector<int> &arr) {
        int c = 0;
        for (int num: arr) {
            if (num % 2) {
                if (++c == 3)
                    return true;
            } else
                c = 0;
        }
        return false;
    }
};

TEST(Solution1550, T1) {
    vector<int> v {2,6,4,1};
    bool expected = false;
    ASSERT_TRUE(expected == Solution1550::threeConsecutiveOdds(v));
}

TEST(Solution1550, T2) {
    vector<int> v {1,2,34,3,4,5,7,23,12};
    bool expected = true;
    ASSERT_TRUE(expected == Solution1550::threeConsecutiveOdds(v));
}