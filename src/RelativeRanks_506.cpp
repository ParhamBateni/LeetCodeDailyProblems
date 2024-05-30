/*
 You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

    The 1st place athlete's rank is "Gold Medal".
    The 2nd place athlete's rank is "Silver Medal".
    The 3rd place athlete's rank is "Bronze Medal".
    For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution506 : public ::testing::Test {
public:
    static vector<string> findRelativeRanks(vector<int> &score) {
        vector<string> s;
        vector<int> cpy = score;
        sort(cpy.begin(), cpy.end(), greater<int>());
        map<int, int> mp;
        int cnt = 0;
        for (int num: cpy) {
            mp[num] = cnt++;
        }
        for (int i = 0; i < score.size(); i++) {
            if (mp[score[i]] == 0)s.push_back("Gold Medal");
            else if (mp[score[i]] == 1) s.push_back("Silver Medal");
            else if (mp[score[i]] == 2) s.push_back("Bronze Medal");
            else s.push_back(to_string(mp[score[i]] + 1));
        }
        return s;
    }
};

TEST(Solution506, T1) {
    vector<int> v = vector<int>{5, 4, 3, 2, 1};
    vector<string> expected = vector<string>{"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    ASSERT_TRUE(expected == Solution506::findRelativeRanks(v));
}

TEST(Solution506, T2) {
    vector<int> v = vector<int>{10, 3, 8, 9, 4};
    vector<string> expected = vector<string>{"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"};
    ASSERT_TRUE(expected == Solution506::findRelativeRanks(v));
}