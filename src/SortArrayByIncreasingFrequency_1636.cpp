/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.



Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]



Constraints:

    1 <= nums.length <= 100
    -100 <= nums[i] <= 100

 */

#include "../utils.h"
#include "gtest/gtest.h"


class Solution1636 : public ::testing::Test {
public:
    static vector<int> frequencySort(vector<int> &nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<int, int> mp;
        for (auto &n: nums) {
            mp[n]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](auto &p1, auto &p2) {
            return p1.second == p2.second ? p1.first > p2.first
                                          : p1.second < p2.second;
        });
        vector<int> res;
        for (auto &p: vec) {
            for (int i = 0; i < p.second; i++)
                res.push_back(p.first);
        }
        return res;
    }
};

TEST(Solution1636, T1) {
    vector<int> nums{1, 1, 2, 2, 2, 3};
    vector<int> expected{3, 1, 1, 2, 2, 2};
    ASSERT_TRUE(expected == Solution1636::frequencySort(nums));
}


TEST(Solution1636, T2) {
    vector<int> nums{2, 3, 1, 3, 2};
    vector<int> expected{1, 3, 3, 2, 2};
    ASSERT_TRUE(expected == Solution1636::frequencySort(nums));
}

TEST(Solution1636, T3) {
    vector<int> nums{-1, 1, -6, 4, 5, -6, 1, 4, 1};
    vector<int> expected{5, -1, 4, 4, -6, -6, 1, 1, 1};
    ASSERT_TRUE(expected == Solution1636::frequencySort(nums));
}