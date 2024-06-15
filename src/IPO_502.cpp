/*
 Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution502 : public ::testing::Test {
public:
    static int findMaximizedCapital(int k, int w, vector<int>& profits,
                                    vector<int>& capital) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        priority_queue<pair<int, int>> q1, q2;
        for (int i = 0; i < profits.size(); i++) {
            if (capital[i] <= w)
                q1.push(pair(profits[i], capital[i]));
            else
                q2.push(pair(-capital[i], profits[i]));
        }
        pair<int, int> p1, p2;
        while (k-- > 0) {
            if (!q1.size())
                break;
            p1 = q1.top();
            q1.pop();
            w += p1.first;
            if (!q2.size())
                continue;
            p2 = q2.top();
            while (q2.size() && -p2.first <= w) {
                q1.push(pair(p2.second, -p2.first));
                q2.pop();
                p2 = q2.top();
            }
        }
        return w;
    }
};

TEST(Solution502, T1) {
    int k = 2;
    int w = 0;
    vector<int> profits{1,2,3};
    vector<int> capitals{0,1,1};
    int expected  = 4;
    ASSERT_EQ(expected,Solution502::findMaximizedCapital(k,w,profits,capitals));
}

TEST(Solution502, T2) {
    int k = 3;
    int w = 0;
    vector<int> profits{1,2,3};
    vector<int> capitals{0,1,2};
    int expected  = 6;
    ASSERT_EQ(expected,Solution502::findMaximizedCapital(k,w,profits,capitals));
}
TEST(Solution502, T3) {
    int k = 1;
    int w = 0;
    vector<int> profits{1,2,3};
    vector<int> capitals{1,1,2};
    int expected  = 0;
    ASSERT_EQ(expected,Solution502::findMaximizedCapital(k,w,profits,capitals));
}