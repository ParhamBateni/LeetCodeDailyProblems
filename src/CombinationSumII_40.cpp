/*
 Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]



Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution40 : public ::testing::Test {
public:
    static vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int >> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }

    static void findCombination(int ind, int target, vector<int> &arr, vector<vector<int >> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
};

TEST(Solution40, T1) {
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> expected{{1, 1, 6},
                                 {1, 2, 5},
                                 {1, 7},
                                 {2, 6}};
    ASSERT_TRUE(expected == Solution40::combinationSum2(candidates, target));
}


TEST(Solution40, T2) {
    vector<int> candidates{2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> expected{{1, 2, 2},
                                 {5}};
    ASSERT_TRUE(expected == Solution40::combinationSum2(candidates, target));
}