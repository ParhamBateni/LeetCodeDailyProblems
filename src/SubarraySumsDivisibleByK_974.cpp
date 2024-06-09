/*
 Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution974 : public ::testing::Test {
public:
    static int subarraysDivByK(vector<int>& nums, int k) {
        cin.tie(0);
        ios::sync_with_stdio(0);
        vector<int> mp(k, 0);
        mp[0] = 1;
        int ans = 0, rem = 0;
        for (int i = 0; i < nums.size(); i++) {
            rem = (rem + nums[i]) % k;
            if (rem < 0)
                rem += k;
            ans += mp[rem]++;
        }
        return ans;
    }
};

TEST(Solution974, T1) {
    vector<int> v {4,5,0,-2,-3,1};
    int k = 5;
    int expected = 7;
    ASSERT_EQ(expected,Solution974::subarraysDivByK(v,k));
}

TEST(Solution974, T2) {
    vector<int> v {5};
    int k = 9;
    int expected = 0;
    ASSERT_EQ(expected,Solution974::subarraysDivByK(v,k));
}