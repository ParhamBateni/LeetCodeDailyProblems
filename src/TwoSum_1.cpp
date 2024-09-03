/*
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]



Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1 : public ::testing::Test {
public:
    static vector<int> twoSum(vector<int> &nums, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        map<int, int> mp;
        int tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp = target - nums[i];
            if (mp.count(tmp))
                return {mp[tmp], i};
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

TEST(Solution1, T1) {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> expected = {0, 1};
    ASSERT_TRUE(expected == Solution1::twoSum(nums, target));
}

TEST(Solution1, T2) {
    vector<int> nums{3, 2, 4};
    int target = 6;
    vector<int> expected = {1, 2};
    ASSERT_TRUE(expected == Solution1::twoSum(nums, target));
}

TEST(Solution1, T3) {
    vector<int> nums{3, 3};
    int target = 6;
    vector<int> expected = {0, 1};
    ASSERT_TRUE(expected == Solution1::twoSum(nums, target));
}
