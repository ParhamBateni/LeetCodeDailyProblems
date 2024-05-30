/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).*/

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1863 : public ::testing::Test {
public:
    static int subsetXORSum(vector<int> &nums, int start = 0, int xr = 0) {
        return start >= nums.size() ? xr : subsetXORSum(nums, start + 1, xr ^ nums[start]) +
                                           subsetXORSum(nums, start + 1, xr);
    }
};


TEST(Solution1863, T1) {
    vector<int> v = vector{1, 3};
    ASSERT_EQ(6, Solution1863::subsetXORSum(v));
}

TEST(Solution1863, T2) {
    vector<int> v = vector{5, 1, 6};
    ASSERT_EQ(28, Solution1863::subsetXORSum(v));
}

TEST(Solution1863, T3) {
    vector<int> v = vector{3, 4, 5, 6, 7, 8};
    ASSERT_EQ(480, Solution1863::subsetXORSum(v));
}