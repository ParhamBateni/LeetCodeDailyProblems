/*
 You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution3075 : public ::testing::Test {
public:
    static long long maximumHappinessSum(vector<int> &happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long s = 0;
        for (int i = 0; i < k; i++) {
            if (happiness[i] - i <= 0) break;
            s += happiness[i] - i;
        }
        return s;
    }
};

TEST(Solution3075, T1) {
    vector<int> v = vector<int>{1, 2, 3};
    EXPECT_EQ(4, Solution3075::maximumHappinessSum(v, 2));
}

TEST(Solution3075, T2) {
    vector<int> v = vector<int>{1, 1, 1};
    EXPECT_EQ(1, Solution3075::maximumHappinessSum(v, 2));
}

TEST(Solution3075, T3) {
    vector<int> v = vector<int>{2, 3, 4, 5};
    EXPECT_EQ(5, Solution3075::maximumHappinessSum(v, 1));
}