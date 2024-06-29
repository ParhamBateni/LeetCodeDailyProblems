/*
 You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.



Example 1:

Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.

Example 2:

Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.



Constraints:

    1 <= n <= 1000
    0 <= edges.length <= min(2000, n * (n - 1) / 2)
    edges[i].length == 2
    0 <= fromi, toi <= n - 1
    fromi != toi
    There are no duplicate edges.
    The graph is directed and acyclic.


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2192 : public ::testing::Test {
public:
    static vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<int> mp1(n);
        vector<vector<int>> mp2(n);
        for (auto &e: edges) {
            mp1[e[1]]++;
            mp2[e[0]].push_back(e[1]);
        }
        vector<set<int>> res;
        res.resize(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (!mp1[i]) s.push(i);
        }
        while (s.size()) {
            int node = s.top();
            s.pop();
            for (int next: mp2[node]) {
                res[next].insert(res[node].begin(), res[node].end());
                res[next].insert(node);
                mp1[next]--;
                if (!mp1[next]) s.push(next);
            }
        }
        vector<vector<int>> vRes;
        for (auto &v: res) {
            vRes.push_back(vector<int>(v.begin(), v.end()));
        }
        return vRes;
    }
};

TEST(Solution2192, T1) {
    vector<vector<int>> v{{0, 3},
                          {0, 4},
                          {1, 3},
                          {2, 4},
                          {2, 7},
                          {3, 5},
                          {3, 6},
                          {3, 7},
                          {4, 6}};
    int n = 8;
    vector<vector<int>> expected{{},
                                 {},
                                 {},
                                 {0, 1},
                                 {0, 2},
                                 {0, 1, 3},
                                 {0, 1, 2, 3, 4},
                                 {0, 1, 2, 3}};
    ASSERT_TRUE(expected == Solution2192::getAncestors(n, v));
}

TEST(Solution2192, T2) {
    vector<vector<int>> v{{0, 1},
                          {0, 2},
                          {0, 3},
                          {0, 4},
                          {1, 2},
                          {1, 3},
                          {1, 4},
                          {2, 3},
                          {2, 4},
                          {3, 4}};
    int n = 5;
    vector<vector<int>> expected{{},
                                 {0},
                                 {0, 1},
                                 {0, 1, 2},
                                 {0, 1, 2, 3}};
    ASSERT_TRUE(expected == Solution2192::getAncestors(n, v));
}