/*
 You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

    Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].

Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.



Example 1:

Input: nums = [4,9,6,10]
Output: true
Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.

Example 2:

Input: nums = [6,8,11,12]
Output: true
Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.

Example 3:

Input: nums = [5,8,3]
Output: false
Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.



Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 1000
    nums.length == n

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2601 : public ::testing::Test {
private:
    static bool isPrime(int n){
        if (n<2) return false;
        for (int i =2;i<=(int)sqrt(n);i++){
            if (n%i==0) return false;
        }
        return true;
    }
public:
    static bool primeSubOperation(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        nums.insert(nums.begin(),0);
        for (int i =1;i<nums.size();i++){
            for (int j = nums[i]-nums[i-1]-1; j>=2;j--){
                if (isPrime(j)) {
                    nums[i] -=j;
                    break;
                }
            }
            if (nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
};

TEST(Solution2601, T1) {
    vector<int> v {4,9,6,10};
    bool expected = true;
    ASSERT_TRUE(expected == Solution2601::primeSubOperation(v));
}
TEST(Solution2601, T2) {
    vector<int> v {6,8,11,12};
    bool expected = true;
    ASSERT_TRUE(expected == Solution2601::primeSubOperation(v));
}
TEST(Solution2601, T3) {
    vector<int> v {5,8,3};
    bool expected = false;
    ASSERT_TRUE(expected == Solution2601::primeSubOperation(v));
}