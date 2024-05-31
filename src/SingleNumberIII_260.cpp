/*
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution260 : public ::testing::Test {
public:
    static vector<int> singleNumber(vector<int>& nums) {
        int xors=0,copyXors;
        int xors1=0;
        for (int i=0;i<nums.size();i++){
            xors^=nums[i];
        }
        copyXors = xors;
        int index = 0;
        while (copyXors!=0){
            if (abs(copyXors%2)==1) {
                break;
            }
            copyXors/=2;
            index++;
        }
        for (int num:nums){
            if (abs((num>>index)%2)==1) xors1^=num;
        }
        return vector<int>{xors1,xors^xors1};
    }
};

TEST(Solution260, T1) {
    vector<int> v{1,2,1,3,2,5};
    vector<int> expected{3,5};
    ASSERT_TRUE(expected==Solution260::singleNumber(v));
}

TEST(Solution260, T2) {
    vector<int> v{-1,0};
    vector<int> expected{-1,0};
    ASSERT_TRUE(expected==Solution260::singleNumber(v));
}
TEST(Solution260, T3) {
    vector<int> v{0,1};
    vector<int> expected{1,0};
    ASSERT_TRUE(expected==Solution260::singleNumber(v));
}
