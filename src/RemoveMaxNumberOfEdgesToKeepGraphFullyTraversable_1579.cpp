/*
Alice and Bob have an undirected graph of n nodes and three types of edges:

    Type 1: Can be traversed by Alice only.
    Type 2: Can be traversed by Bob only.
    Type 3: Can be traversed by both Alice and Bob.

Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.



Example 1:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

Example 2:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

Example 3:

Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.





Constraints:

    1 <= n <= 105
    1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
    edges[i].length == 3
    1 <= typei <= 3
    1 <= ui < vi <= n
    All tuples (typei, ui, vi) are distinct.


 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1579 : public ::testing::Test {
    struct unionFind {
        vector<int> parent;
        vector<int> size;
        int c;
        unionFind(int n) {
            size = vector<int>(n + 1, 1);
            parent = vector<int>(n + 1);
            iota(parent.begin(), parent.end(), 0);
            c = n;
        }

        int find(int p) {
            if (parent[p] != p)
                parent[p] = find(parent[p]);
            return parent[p];
        }

        bool _union(int u, int v) {
            int rootU = find(u), rootV = find(v);
            if (rootU == rootV)
                return false;
            if (size[rootU] < size[rootV]) {
                parent[rootU] = parent[rootV];
                size[rootU]++;
            } else {
                parent[rootV] = parent[rootU];
                size[rootV]++;
            }
            c--;
            return true;
        }
    };

public:
    static int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unionFind uf1 = unionFind(n), uf2 = unionFind(n);
        int cnt = 0;
        for (auto& edge : edges) {
            if (edge[0] == 3 && uf1._union(edge[1], edge[2]) &&
                uf2._union(edge[1], edge[2]))
                cnt++;
        }
        for (auto& edge : edges) {
            if (edge[0] == 1 && uf1._union(edge[1], edge[2]))
                cnt++;
            else if (edge[0] == 2 && uf2._union(edge[1], edge[2]))
                cnt++;
        }
        if (uf1.c == 1 && uf2.c == 1)
            return edges.size() - cnt;
        else
            return -1;
    }
};

TEST(Solution1579,T1){
    vector<vector<int>> edges {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    int n = 4;
    int expected = 2;
    ASSERT_EQ(expected,Solution1579::maxNumEdgesToRemove(n,edges));
}

TEST(Solution1579,T2){
    vector<vector<int>> edges {{3,2,3},{1,1,2},{2,3,4}};
    int n = 4;
    int expected = -1;
    ASSERT_EQ(expected,Solution1579::maxNumEdgesToRemove(n,edges));
}

TEST(Solution1579,T3){
    vector<vector<int>> edges {{3,1,2},{3,2,3},{1,1,4},{2,1,4}};
    int n = 4;
    int expected = 0;
    ASSERT_EQ(expected,Solution1579::maxNumEdgesToRemove(n,edges));
}