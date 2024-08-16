/*
 The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.



Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:

Input: nums = [1,1,1], k = 2
Output: 0

Example 3:

Input: nums = [1,6,1], k = 3
Output: 5

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution719 : public ::testing::Test {
public:
    static int cntPairs(int x, vector<int> &nums) {//sliding window
        const int n = nums.size();
        int cnt = 0;
        for (int l = 0, r = 1; r < n; r++) {
            while (r > l && nums[r] - nums[l] > x)
                l++;
            cnt += r - l;
        }
        return cnt;
    }

    static int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        const int M = nums.back();

        //Binary search
        int l = 0, r = M, m;
        while (l < r) {
            m = (r + l) / 2;
            if (cntPairs(m, nums) < k)
                l = m + 1;
            else r = m;
        }
        return l;
    }
};

TEST(Solution719, T1) {
    vector<int> nums{1, 3, 1};
    int k = 1;
    int expected = 0;
    ASSERT_TRUE(expected == Solution719::smallestDistancePair(nums, k));
}


TEST(Solution719, T2) {
    vector<int> nums{1, 1, 1};
    int k = 2;
    int expected = 0;
    ASSERT_TRUE(expected == Solution719::smallestDistancePair(nums, k));
}