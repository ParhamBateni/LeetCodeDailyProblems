/*
 ou are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.



Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.



Constraints:

    2 <= n <= 10^4
    0 <= start, end < n
    start != end
    0 <= a, b < n
    a != b
    0 <= succProb.length == edges.length <= 2*10^4
    0 <= succProb[i] <= 1
    There is at most one edge between every two nodes.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1514 : public ::testing::Test {
public:
    static double maxProbability(int n, vector<vector<int>> &edges,
                                 vector<double> &succProb, int start_node,
                                 int end_node) {
        map<int, vector<pair<int, double>>> neighbours;
        for (int i = 0; i < edges.size(); i++) {
            neighbours[edges[i][0]].push_back({edges[i][1], succProb[i]});
            neighbours[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        auto cmp = [](pair<int, double> &p1, pair<int, double> &p2) {
            return p1.second < p2.second;
        };

        priority_queue<pair<int, double>, vector<pair<int, double>>,
                decltype(cmp)>
                pq(cmp);

        pq.push({start_node, 1});
        pair<int, double> tmp;
        set<int> seen;
        while (pq.size()) {
            tmp = pq.top();
            pq.pop();
            if (tmp.first == end_node)
                return tmp.second;
            seen.insert(tmp.first);
            for (pair<int, double> neighbour: neighbours[tmp.first]) {
                if (seen.count(neighbour.first))
                    continue;
                pq.push({neighbour.first, tmp.second * neighbour.second});
            }
        }
        return 0;
    }
};

TEST(Solution1514, T1) {
    int n = 3;
    vector<vector<int>> edges{{0, 1},
                              {1, 2},
                              {0, 2}};
    vector<double> succProb{0.5, 0.5, 0.2};
    int start_node = 0, end_node = 2;
    double expected = 0.25;
    ASSERT_TRUE(expected == Solution1514::maxProbability(n, edges, succProb, start_node, end_node));
}

TEST(Solution1514, T2) {
    int n = 3;
    vector<vector<int>> edges{{0, 1},
                              {1, 2},
                              {0, 2}};
    vector<double> succProb{0.5, 0.5, 0.3};
    int start_node = 0, end_node = 2;
    double expected = 0.3;
    ASSERT_TRUE(expected == Solution1514::maxProbability(n, edges, succProb, start_node, end_node));
}

TEST(Solution1514, T3) {
    int n = 3;
    vector<vector<int>> edges{{0, 1}};
    vector<double> succProb{0.5};
    int start_node = 0, end_node = 2;
    double expected = 0;
    ASSERT_TRUE(expected == Solution1514::maxProbability(n, edges, succProb, start_node, end_node));
}