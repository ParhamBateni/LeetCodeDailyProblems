/*
 Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.



Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16



Constraints:

    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1248 : public ::testing::Test {
public:
    static int numberOfSubarrays(vector<int> &nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size(), s = n, e = 0, c = 0;
        for (int i = 0; i < n; i++)
            nums[i] %= 2;
        while (e < n && c != k) {
            if (nums[e++]) {
                c++;
                s = min(s, e);
            }
        }
        if (c != k)
            return 0;
        int cm = s, ans = 0;
        while (e < n) {
            ans += cm;
            while (e < n && !nums[e++])
                ans += cm;
            cm = 1;
            while (s < e && !nums[s++])
                cm++;
        }
        if (nums[n - 1])
            return ans + cm;
        return ans;
    }
};

TEST(Solution1248, T1) {
    int k = 3;
    vector<int> nums{1, 1, 2, 1, 1};
    int expected = 2;
    ASSERT_EQ(expected, Solution1248::numberOfSubarrays(nums, k));
}

TEST(Solution1248, T2) {
    int k = 1;
    vector<int> nums{2, 4, 6};
    int expected = 0;
    ASSERT_EQ(expected, Solution1248::numberOfSubarrays(nums, k));
}

TEST(Solution1248, T3) {
    int k = 2;
    vector<int> nums{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int expected = 16;
    ASSERT_EQ(expected, Solution1248::numberOfSubarrays(nums, k));
}