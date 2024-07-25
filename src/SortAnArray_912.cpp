/*
 Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.



Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.



Constraints:

    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution912 : public ::testing::Test {
public:
    static vector<int> sortArray(vector<int>& nums) {
        const int vmin=-5*1e4, N=1e5+1;
        int freq[N]={0}, xMax=-1, xMin=N;
        for(int x:nums) {
            x-=vmin;
            freq[x]++;
            xMax=max(x, xMax);
            xMin=min(x, xMin);
        }
        for(int i=0, x=xMin; x<=xMax; x++){
            int f=freq[x];
            fill(nums.begin()+i, nums.begin()+i+f, x+vmin);//adjust back
            i+=f;
        }
        return nums;
    }
};

TEST(Solution912, T1) {
    vector<int> nums{5,2,3,1};
    vector<int> expected{1,2,3,5};
    ASSERT_TRUE(expected==Solution912::sortArray(nums));
}


TEST(Solution912, T2) {
    vector<int> nums{5,1,1,2,0,0};
    vector<int> expected{0,0,1,1,2,5};
    ASSERT_TRUE(expected==Solution912::sortArray(nums));
}
