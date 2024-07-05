/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.



Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000



Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution350 : public ::testing::Test {
public:
    static vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        int occ1[1001], occ2[1001];
        for (auto &num: nums1)
            occ1[num]++;
        for (auto &num: nums2)
            occ2[num]++;
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < min(occ1[i], occ2[i]); j++)
                res.push_back(i);
        return res;
    }
};

TEST(Solution350, T1) {
    vector<int> v1{1, 2, 2, 1};
    vector<int> v2{2, 2};
    vector<int> expected{2, 2};
    ASSERT_TRUE(expected == Solution350::intersect(v1, v2));
}

TEST(Solution350, T2) {
    vector<int> v1{4,9,5};
    vector<int> v2{9,4,9,8,4};
    vector<int> expected{4, 9};
    ASSERT_TRUE(expected == Solution350::intersect(v1, v2));
}