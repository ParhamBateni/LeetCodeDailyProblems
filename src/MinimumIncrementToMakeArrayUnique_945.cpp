/*
 You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution945 : public ::testing::Test {
public:
    static int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int cnt = 0, prev = -1;
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (prev >= num) cnt += ++prev - num;
            else prev = num;
        }
        return cnt;
    }
};

TEST(Solution945, T1) {
    vector<int> v{1,2,2};
    int expected  = 1;
    ASSERT_EQ(expected,Solution945::minIncrementForUnique(v));
}

TEST(Solution945, T2) {
    vector<int> v{3,2,1,2,1,7};
    int expected  = 6;
    ASSERT_EQ(expected,Solution945::minIncrementForUnique(v));
}