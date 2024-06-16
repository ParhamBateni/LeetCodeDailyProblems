/*
 Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.
 Example 1:

Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].

Example 3:

Input: nums = [1,2,2], n = 5
Output: 0

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution330 : public ::testing::Test {
public:
    static int minPatches(vector<int>& nums, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long p=0;
        int cnt = 0,i=0;
        while (i < nums.size()) {
            while (p<n && p<nums[i]-1){
                cnt++;
                p=2*p+1;
            }
            if (p>=n) break;
            p+=nums[i++];
        }
        while (p<n){
            cnt++;
            p=2*p+1;
        }
        return cnt;
    }
};

TEST(Solution330, T1) {
    vector<int> nums{1,3};
    int n = 6;
    int expected   = 1;
    ASSERT_EQ(expected,Solution330::minPatches(nums,n));
}

TEST(Solution330, T2) {
    vector<int> nums{1,5,10};
    int n = 20;
    int expected   = 2;
    ASSERT_EQ(expected,Solution330::minPatches(nums,n));
}

TEST(Solution330, T3) {
    vector<int> nums{1,2,2};
    int n = 5;
    int expected   = 0;
    ASSERT_EQ(expected,Solution330::minPatches(nums,n));
}