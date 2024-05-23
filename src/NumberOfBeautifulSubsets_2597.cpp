/*
You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
 */

#include "../utils.h"
#include "gtest/gtest.h"

char freq[1001] = {0};
int cnt, n;

class Solution2597 : public ::testing::Test {
public:
    static void backtrack(int idx, vector<int> &nums, int k) {
        if (idx == n) {
            cnt++;
            return;
        }
        backtrack(idx + 1, nums, k);
        int x = nums[idx];
        if ((x - k < 0 || freq[x - k] == 0) &&
            (x + k > 1000 || freq[x + k] == 0)) {
            freq[x]++;
            backtrack(idx + 1, nums, k);
            freq[x]--;
        }
    }

    static int beautifulSubsets(vector<int> &nums, int k) {
        n = nums.size();
        freq[1001] = {0};
        cnt = 0;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, k);
        return --cnt;
    }
};


TEST(Solution2597, T1) {
    vector<int> nums{2, 4, 6};
    int k = 2;
    ASSERT_EQ(4, Solution2597::beautifulSubsets(nums, k));
}

TEST(Solution2597, T2) {
    vector<int> nums{1};
    int k = 1;
    ASSERT_EQ(1, Solution2597::beautifulSubsets(nums, k));
}