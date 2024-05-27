/*
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1608 : public ::testing::Test {
public:
    static int specialArray(vector<int>& nums) {
        int n = nums.size();
        int occ[1001] = {0};
        for (int n:nums){
            occ[n]++;
        }
        for (int i=999;i>=0;i--){
            occ[i] +=occ[i+1];
            if (occ[i]==i) return i;
        }
        return -1;
    }
};


TEST(Solution1608, T1) {
    vector<int>v{0,0};
    ASSERT_EQ(-1, Solution1608::specialArray(v));
}

TEST(Solution1608, T2) {
    vector<int>v{3,5};
    ASSERT_EQ(2, Solution1608::specialArray(v));
}
TEST(Solution1608, T3) {
    vector<int>v{0,4,3,0,4};
    ASSERT_EQ(3, Solution1608::specialArray(v));
}