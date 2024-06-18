/*
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

    difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
    worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).

Every worker can be assigned at most one job, but one job can be completed multiple times.

    For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.

Return the maximum profit we can achieve after assigning the workers to the jobs.



Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.

Example 2:

Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0



Constraints:

    n == difficulty.length
    n == profit.length
    m == worker.length
    1 <= n, m <= 104
    1 <= difficulty[i], profit[i], worker[i] <= 105


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution826 : public ::testing::Test {
public:
    static int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                                   vector<int> &worker) {
        ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {difficulty[i], profit[i]};
        }
        sort(pairs.begin(), pairs.end(), [](auto &p1, auto &p2) {
            return p1.first < p2.first ? 1
                                       : p1.first == p2.first ? p1.second > p2.second
                                                              : 0;
        });
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, pairs[i].second);
            pairs[i].second = mx;
        }
        mx = 0;
        int low, high, mid;
        for (int i = 0; i < m; i++) {
            low = 0;
            high = n - 1;
            mid = (low + high) / 2;
            while (low < high - 1) {
                if (worker[i] > pairs[mid].first)
                    low = mid;
                else if (worker[i] < pairs[mid].first)
                    high = mid;
                else if (worker[i] == pairs[mid].first)
                    break;
                mid = (low + high) / 2;
            }
            if (worker[i] >= pairs[mid + 1].first)
                mx += pairs[mid + 1].second;
            else if (worker[i] >= pairs[mid].first)
                mx += pairs[mid].second;
        }
        return mx;
    }
};

TEST(Solution826, T1) {
    vector<int> difficulty{2, 4, 6, 8, 10};
    vector<int> profit{10, 20, 30, 40, 50};
    vector<int> worker{4, 5, 6, 7};
    int expected = 100;
    ASSERT_EQ(expected, Solution826::maxProfitAssignment(difficulty, profit, worker));
}

TEST(Solution826, T2) {
    vector<int> difficulty{85, 47, 57};
    vector<int> profit{24, 66, 99};
    vector<int> worker{40, 25, 25};
    int expected = 0;
    ASSERT_EQ(expected, Solution826::maxProfitAssignment(difficulty, profit, worker));
}