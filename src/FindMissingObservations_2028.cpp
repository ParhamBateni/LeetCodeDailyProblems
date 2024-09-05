/*
 You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.



Example 1:

Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.

Example 2:

Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.

Example 3:

Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.



Constraints:

    m == rolls.length
    1 <= n, m <= 105
    1 <= rolls[i], mean <= 6


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2028 : public ::testing::Test {
public:
    static vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        mean *= n + rolls.size();
        for (int num: rolls) {
            mean -= num;
        }
        vector<int> res;
        float m = mean * 1.0 / n;
        if (m > 6 || m < 1)
            return {};
        else {
            m = (int) m;
            int b = mean - n * m;
            int a = n - b;
            for (int i = 0; i < b; i++)
                res.push_back(m + 1);
            for (int i = 0; i < a; i++)
                res.push_back(m);
        }
        return res;
    }
};

TEST(Solution2028, T1) {
    vector<int> rolls{3, 2, 4, 3};
    int mean = 4;
    int n = 2;
    vector<int> expected{6, 6};
    ASSERT_TRUE(expected == Solution2028::missingRolls(rolls, mean, n));
}

TEST(Solution2028, T2) {
    vector<int> rolls{1, 5, 6};
    int mean = 3;
    int n = 4;
    vector<int> expected{3, 2, 2, 2};
    ASSERT_TRUE(expected == Solution2028::missingRolls(rolls, mean, n));
}

TEST(Solution2028, T3) {
    vector<int> rolls{1, 2, 3, 4};
    int mean = 6;
    int n = 4;
    vector<int> expected{};
    ASSERT_TRUE(expected == Solution2028::missingRolls(rolls, mean, n));
}