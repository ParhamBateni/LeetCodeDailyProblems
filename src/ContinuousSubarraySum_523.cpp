/*
 Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

    its length is at least two, and
    the sum of the elements of the subarray is a multiple of k.

Note that:

    A subarray is a contiguous part of the array.
    An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution523 : public ::testing::Test {
public:
    static bool checkSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        unordered_map<int,int> mp;
        mp[0]= 1;
        int prev = nums[0]%k;
        int mod;
        for (int i=1;i<nums.size();i++){
            mod = (prev + nums[i])%k;
            if (mp[mod]) return true;
            mp[prev]++;
            prev=mod;
        }
        return false;
    }
};

TEST(Solution523, T1) {
    vector<int> v {23,2,4,6,7};
    int k = 6;
    bool expected = true;
    ASSERT_EQ(expected,Solution523::checkSubarraySum(v,k));
}

TEST(Solution523, T2) {
    vector<int> v {23,2,6,4,7};
    int k = 6;
    bool expected = true;
    ASSERT_EQ(expected,Solution523::checkSubarraySum(v,k));
}
TEST(Solution523, T3) {
    vector<int> v {23,2,6,4,7};
    int k = 13;
    bool expected = false;
    ASSERT_EQ(expected,Solution523::checkSubarraySum(v,k));
}