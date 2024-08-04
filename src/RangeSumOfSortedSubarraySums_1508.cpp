/*
 * You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.



Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13.

Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.

Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50



Constraints:

    n == nums.length
    1 <= nums.length <= 1000
    1 <= nums[i] <= 100
    1 <= left <= right <= n * (n + 1) / 2

 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1508 : public ::testing::Test {
public:
    static int rangeSum(vector<int> &nums, int n, int left, int right) {
        vector<int> sums(n * (n + 1) / 2);
        int s, j, c = 0;
        for (int i = 0; i < n; i++) {
            s = 0;
            j = i;
            while (j < n) {
                s += nums[j++];
                sums[c++] = s;
            }
        }
        sort(sums.begin(), sums.end());
        s = 0;
        int mod = 1e9 + 7;
        for (int i = left - 1; i < right; i++) {
            s = (s + sums[i]) % mod;
        }
        return s;
    }
};

TEST(Solution1508, T1) {
    vector<int> nums{1, 2, 3, 4};
    int n = 4;
    int left = 1;
    int right = 5;
    int expected = 13;
    ASSERT_TRUE(expected == Solution1508::rangeSum(nums, n, left, right));
}

TEST(Solution1508, T2) {
    vector<int> nums{1, 2, 3, 4};
    int n = 4;
    int left = 3;
    int right = 4;
    int expected = 6;
    ASSERT_TRUE(expected == Solution1508::rangeSum(nums, n, left, right));
}

TEST(Solution1508, T3) {
    vector<int> nums{1, 2, 3, 4};
    int n = 4;
    int left = 1;
    int right = 10;
    int expected = 50;
    ASSERT_TRUE(expected == Solution1508::rangeSum(nums, n, left, right));
}