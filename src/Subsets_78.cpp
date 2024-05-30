/*
Given an integer array nums of unique elements, return all possible
subsets
(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution78 : public ::testing::Test {
private:
    static set<vector<int>> traverse(vector<int> &nums, int start) {
        if (start == nums.size()) return set<vector<int>>{vector<int>{}};
        set<vector<int>> s1 = traverse(nums, start + 1);
        set<vector<int>> s2 = s1;
        for (auto v: s1) {
            v.push_back(nums[start]);
            s2.insert(v);
        }
        return s2;
    }

public:
    static vector<vector<int>> subsets(vector<int> &nums) {
        set<vector<int>> t = traverse(nums, 0);
        return vector<vector<int>>(t.begin(), t.end());
    }
};


TEST(Solution78, T1) {
    vector<int> v{1, 2, 3};
    ASSERT_EQ(8, Solution78::subsets(v).size());
}

TEST(Solution78, T2) {
    vector<int> v{0};
    ASSERT_EQ(2, Solution78::subsets(v).size());
}