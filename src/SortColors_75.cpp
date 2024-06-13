/*
 Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution75 : public ::testing::Test {
public:
    static void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j],nums[j-1]);
                }
            }
        }
    }
};

TEST(Solution75, T1) {
    vector<int> v{2,0,2,1,1,0};
    vector<int> expected{0,0,1,1,2,2};
    Solution75::sortColors(v);
    ASSERT_TRUE(expected==v);
}
TEST(Solution75, T2) {
    vector<int> v{2,0,1};
    vector<int> expected{0,1,2};
    Solution75::sortColors(v);
    ASSERT_TRUE(expected==v);
}