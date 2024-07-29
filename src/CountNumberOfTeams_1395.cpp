/*
 There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

    Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).



Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).

Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:

Input: rating = [1,2,3,4]
Output: 4



Constraints:

    n == rating.length
    3 <= n <= 1000
    1 <= rating[i] <= 105
    All the integers in rating are unique.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1395 : public ::testing::Test {
public:
    static int numTeams(vector<int> &rating) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        map<int, vector<int>> biggers;
        map<int, vector<int>> smallers;
        int n = rating.size(), num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rating[j] > rating[i])
                    biggers[rating[i]].push_back(rating[j]);
                else if (rating[j] < rating[i])
                    smallers[rating[i]].push_back(rating[j]);
            }
        }
        for (auto &m: biggers) {
            for (auto &v: m.second) {
                num += biggers[v].size();
            }
        }
        for (auto &m: smallers) {
            for (auto &v: m.second) {
                num += smallers[v].size();
            }
        }
        return num;
    }
};

TEST(Solution1395, T1) {
    vector<int> rating{2, 5, 3, 4, 1};
    int expected = 3;
    ASSERT_EQ(expected, Solution1395::numTeams(rating));
}

TEST(Solution1395, T2) {
    vector<int> rating{2, 1, 3};
    int expected = 0;
    ASSERT_EQ(expected, Solution1395::numTeams(rating));
}

TEST(Solution1395, T3) {
    vector<int> rating{1, 2, 3, 4};
    int expected = 4;
    ASSERT_EQ(expected, Solution1395::numTeams(rating));
}