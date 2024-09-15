/*
 You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

    In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.

Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.



Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.

Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.



Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 106

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2419 : public ::testing::Test {
public:
    static int longestSubarray(vector<int> &nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
            }
        }
        int i = 0, end;
        int ans = 1;
        while (i < nums.size()) {
            if (nums[i] != mx) {
                i++;
                continue;
            }
            end = i + 1;
            while (end < nums.size() and nums[end] == mx)
                end++;
            ans = max(ans, end - i);
            i = end;
        }
        return ans;
    }
};

TEST(Solution2419, T1) {
    vector<int> nums{1, 2, 3, 3, 2, 2};
    int expected = 2;
    ASSERT_TRUE(expected == Solution2419::longestSubarray(nums));
}

TEST(Solution2419, T2) {
    vector<int> nums{1, 2, 3, 4};
    int expected = 1;
    ASSERT_TRUE(expected == Solution2419::longestSubarray(nums));
}